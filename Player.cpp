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
  UpdateKeys();
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
  if (y_coord_ >= 400 + 200) {
    STATE = stay;
    y_speed_ = 0;
    is_on_ground_ = true;
  }
  //###############################################//

  manager.UpdateFrame(time);

  ResetKeys();
}

void Player::SetKeys(std::string key, bool flag) { keys_[key] = flag; }

double Player::GetXCoord() { return x_coord_; }

double Player::GetYCoord() { return y_coord_; }
