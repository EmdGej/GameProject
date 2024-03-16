#include "Bullet.hpp"

Bullet::Bullet(AnimationManager manager, double x_coord, double y_coord,
               double x_speed, bool direction)
    : manager_(manager),
      x_coord_(x_coord),
      y_coord_(y_coord),
      x_speed_(x_speed),
      direction_(direction) {
  if (!direction_) {
    x_speed_ *= -1;
  }
}

void Bullet::UpdateBullet(const MapParams& map_params,
                          const std::unordered_set<char>& blocks, double time) {
  x_coord_ += x_speed_ * time;

  manager_.SetAnimation("bullet");

  CheckBlocksCollision(map_params, blocks);

  manager_.UpdateFrame(time);
}

void Bullet::DrawBullet(sf::RenderWindow& window, double offsetX,
                        double offsetY) {
  manager_.Draw(window, x_coord_ - offsetX, y_coord_ - offsetY);
}

double Bullet::GetXCoord() const { return x_coord_; }
double Bullet::GetYCoord() const { return y_coord_; }

double Bullet::GetXSpeed() const { return x_speed_; }
bool Bullet::GetIsAlive() const { return is_alive_; }

double Bullet::GetBulletWidth() { return manager_.GetAnimationWidth(); }
double Bullet::GetBulletHeight() { return manager_.GetAnimationHeight(); }

void Bullet::SetXSpeed(double value) { x_speed_ = value; }
void Bullet::SetIsAlive(bool value) { is_alive_ = value; }
