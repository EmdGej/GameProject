#ifndef ENEMY
#define ENEMY

#include <iostream>

#include "AbstractEntity.hpp"
#include "BulletManager.hpp"
class Enemy : public AbstractEntity {
 public:
  Enemy(AnimationManager manager, double x_coord, double y_coord, double x_left,
        double x_right, double x_speed);

  void UpdateEnemy(double time, std::list<Bullet*>* bullets);

  void DrawEnemy(sf::RenderWindow& window, double offsetX, double offsetY);

  void CheckBullets(std::list<Bullet*>* bullets);

  double GetXCoord() const;
  double GetYCoord() const;

  double GetXSpeed() const;

  bool GetIsAlive() const;

  void SetSpeedX(double value);

  void SetDirection(bool flag);

  void SetIsAlive(bool flag);

 private:
  void CheckBoundaries() {
    if (x_coord_ <= x_left_) {
      direction_ = !direction_;
      x_speed_ = -x_speed_;
      x_coord_ = x_left_;
    }

    if (x_coord_ >= x_right_) {
      direction_ = !direction_;
      x_speed_ = -x_speed_;
      x_coord_ = x_right_;
    }
  }
  AnimationManager manager_;

  bool direction_;

  bool is_alive_;

  double x_left_;
  double x_right_;
};

#endif