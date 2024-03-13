#include "Player.hpp"

Player::Player(double x_coord, double y_coord, int32_t health, int32_t damage,
               double acceleration) {
  x_coord_ = x_coord;
  y_coord_ = y_coord;
  health_ = health;
  damage_ = damage;

  acceleration_ = acceleration;
  is_on_ground_ = false;

  STATE = stay;

  FillMapWithKeys();
}

void Player::UpdatePlayer(AnimationManager& manager, const MapParams& params,
                          double time) {
  if (time > kLoadTime) {
    return;
  }

  UpdateKeys(time);
  SetState(manager);

  if (direction_) {
    manager.SetFlip(true);
  } else {
    manager.SetFlip(false);
  }

  x_coord_ += x_speed_ * time;
  CollisionX(params, manager);

  y_speed_ += (!is_on_ground_) * acceleration_ * time;
  y_coord_ += y_speed_ * time;
  is_on_ground_ = false;
  CollisionY(params, manager);

  manager.UpdateFrame(time);
  ResetKeys();
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

int32_t Player::GetAnimationHeight(AnimationManager& manager) const {
  return manager.GetAnimationHeight();
}
int32_t Player::GetAnimationWidth(AnimationManager& manager) const {
  return manager.GetAnimationWidth();
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