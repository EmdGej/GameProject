#include "Player.hpp"
#include <unordered_set>

Player::Player() = default;

Player::Player(AnimationManager manager, double x_coord, double y_coord, int32_t health, int32_t damage,
               double acceleration) {
  x_coord_ = x_coord;
  y_coord_ = y_coord;
  health_ = health;
  damage_ = damage;

  manager_ = manager;

  acceleration_ = acceleration;
  is_on_ground_ = false;

  STATE = stay;

  FillMapWithKeys();
}

void Player::UpdatePlayer(const MapParams& params, const std::unordered_set<char>& blocks,
                          const std::unordered_set<char>& die_blocks, double time) {
  if (time > kLoadTime) {
    return;
  }

  if (health_ <= 0) {
    x_speed_ = 0;
  }
  
  CheckDie(params, die_blocks);

  UpdateKeys(time);
  SetState();

  if (direction_) {
    manager_.SetFlip(true);
  } else {
    manager_.SetFlip(false);
  }

  x_coord_ += x_speed_ * time;
  CollisionX(params, blocks);

  y_speed_ += (!is_on_ground_) * acceleration_ * time;
  y_speed_ = std::min(y_speed_, kSpeedY);
  y_coord_ += y_speed_ * time;
  is_on_ground_ = false;
  CollisionY(params, blocks);

  manager_.UpdateFrame(time);
  ResetKeys();
}

void Player::DrawPlayer(sf::RenderWindow& window, double offsetX, double offsetY) {
  manager_.Draw(window, x_coord_ - offsetX, y_coord_ - offsetY);
}

void Player::SetKeys(std::string key, bool flag) { keys_[key] = flag; }

double Player::GetXCoord() const { return x_coord_; }
double Player::GetYCoord() const { return y_coord_; }

double Player::GetStaminaCoef() const { return kStaminaCoef; }
double Player::GetStaminaLoss() const { return kStaminaLoss; }
double Player::GetStaminaGet() const { return kStaminaGet; }
double Player::GetTimeToRestoreStamina() const { return kTimeToRestoreStamina; }

double Player::GetXSpeed() const { return kSpeedX; }
double Player::GetYSpeed() const { return kSpeedY; }

double Player::GetCurXSpeed() const { return x_speed_; }
double Player::GetCurYSpeed() const { return y_speed_; }

bool Player::GetDirection() const { return direction_; }
bool Player::GetIsOnGround() const { return is_on_ground_; }

int32_t Player::GetHealth() const { return health_; }

int32_t Player::GetAnimationHeight() {
  return manager_.GetAnimationHeight();
}

int32_t Player::GetAnimationWidth() {
  return manager_.GetAnimationWidth();
}
  
void Player::SetDoubleJumpAbility(bool ability) {
  has_double_jump_ = ability;
  is_double_jump_available_ = has_double_jump_;
}

void Player::SetSpeedX(double value) { kSpeedX = value; }
void Player::SetSpeedY(double value) { kSpeedY = value; }

void Player::SetStaminaCoef(double value) { kStaminaCoef = value; }
void Player::SetStaminaLoss(double value) { kStaminaLoss = value; }
void Player::SetStaminaGet(double value) { kStaminaGet = value; }
void Player::SetTimeToRestoreStamina(double value) {
  kTimeToRestoreStamina = value;
}

void Player::SetIsOnGround(bool flag) { is_on_ground_ = flag; }

void Player::SetXCoord(double coord) { x_coord_ = coord; }
void Player::SetYCoord(double coord) { y_coord_ = coord; }

void Player::SetCurXSpeed(double value) { x_speed_ = value; }
void Player::SetCurYSpeed(double value) { y_speed_ = value; }

void Player::SetAcceleration(double value) { acceleration_ = value; }

void Player::SetHealth(int32_t value) { health_ = value; }

void Player::SetDefault() {
  x_coord_ = DefaultSettings::PlayerSettings::x_coord;
  y_coord_ = DefaultSettings::PlayerSettings::y_Coord;
  health_ = DefaultSettings::PlayerSettings::health;
  damage_ = DefaultSettings::PlayerSettings::damage;
  acceleration_ = DefaultSettings::PlayerSettings::acceleration;
  stamina_ = DefaultSettings::PlayerSettings::stamina;
  STATE = stay;
}