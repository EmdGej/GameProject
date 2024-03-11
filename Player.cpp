#include "Player.hpp"

Player::Player(double x_coord, double y_coord, int32_t health, int32_t damage,
               double acceleration) {
  x_coord_ = x_coord;
  y_coord_ = y_coord;
  health_ = health;
  damage_ = damage;

  acceleration_ = acceleration;
  is_on_ground_ = true;

  STATE = stay;

  FillMapWithKeys();
}

void Player::UpdatePlayer(AnimationManager& manager, double time) {
  UpdateKeys(time);
  SetState(manager);

  if (direction_) {
    manager.SetFlip(true);
  } else {
    manager.SetFlip(false);
  }

  y_speed_ += (!is_on_ground_) * acceleration_ * time;

  x_coord_ += x_speed_ * time;
  y_coord_ += y_speed_ * time;

  //###############################################// // to check jump ability
  if (y_coord_ >= 400 + 200 && !is_on_ground_) {
    is_on_ground_ = true;
    STATE = stay;
    y_speed_ = 0;

    is_double_jump_available_ = has_double_jump_;
  }
  //###############################################//

  manager.UpdateFrame(time);
  ResetKeys();
}

void Player::SetKeys(std::string key, bool flag) { keys_[key] = flag; }

double Player::GetXCoord() { return x_coord_; }

double Player::GetYCoord() { return y_coord_; }

void Player::SetDoubleJumpAbility(bool ability) {
  has_double_jump_ = ability;
  is_double_jump_available_ = has_double_jump_;
}

void Player::SetSpeedX(double value) { kSpeedX = value; }
void Player::SetSpeedY(double value) { kSpeedY = value; }
void Player::SetStaminaCoef(double value) { kStaminaCoef = value; }
void Player::SetStaminaLoss(double value) { kStaminaLoss = value; }
void Player::SetStaminaGet(double value) { kStaminaGet = value; }
void Player::SetTimeToRestoreStamina(double value) { kTimeToRestoreStamina = value; }
