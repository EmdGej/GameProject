#include "Enemy.hpp"

Enemy::Enemy(AnimationManager manager, double x_coord, double y_coord,
             double x_left, double x_right, double x_speed) {
  x_coord_ = x_coord;
  y_coord_ = y_coord;
  x_left_ = x_left;
  x_right_ = x_right;
  direction_ = true;
  is_alive_ = true;
  manager_ = manager;
  x_speed_ = x_speed;
}
void Enemy::UpdateEnemy(double time, std::list<Bullet*>* bullets) {
  if (is_alive_) {
    CheckBullets(bullets);
    manager_.SetAnimation("xeno-grunt-run");
  } else {
    manager_.SetAnimation("xeno-grunt-death-grounded");
    x_speed_ = 0;
    manager_.UpdateFrame(time);
    return;
  }

  if (direction_) {
    manager_.SetFlip(true);
  } else {
    manager_.SetFlip(false);
  }
  x_coord_ += x_speed_ * time;
  CheckBoundaries();

  manager_.UpdateFrame(time);
}

void Enemy::DrawEnemy(sf::RenderWindow& window, double offsetX,
                      double offsetY) {
  manager_.Draw(window, x_coord_ - offsetX, y_coord_ - offsetY);
}

void Enemy::CheckBullets(std::list<Bullet*>* bullets) {
  for (auto iter = bullets->begin(); iter != bullets->end(); ++iter) {
    sf::Rect<double> bullet_rect((*iter)->GetXCoord(), (*iter)->GetYCoord(),
                                 (*iter)->GetBulletWidth(),
                                 (*iter)->GetBulletHeight());
    sf::Rect<double> enemy_rect(x_coord_, y_coord_,
                                manager_.GetAnimationWidth(),
                                manager_.GetAnimationHeight());
    if (bullet_rect.intersects(enemy_rect)) {
      (*iter)->SetIsAlive(false);
      is_alive_ = false;
      return;
    }
  }
}

double Enemy::GetXCoord() const { return x_coord_; }
double Enemy::GetYCoord() const { return y_coord_; }

double Enemy::GetXSpeed() const { return x_speed_; }

bool Enemy::GetIsAlive() const { return is_alive_; }

void Enemy::SetSpeedX(double value) { x_speed_ = value; }

void Enemy::SetDirection(bool flag) { direction_ = flag; }

void Enemy::SetIsAlive(bool flag) { is_alive_ = flag; }

double Enemy::GetAnimationHeight() { return manager_.GetAnimationHeight(); }
double Enemy::GetAnimationWidth() { return manager_.GetAnimationWidth(); }
