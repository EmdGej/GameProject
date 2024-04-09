#ifndef ENEMY_MANAGER
#define ENEMY_MANAGER

#include "../BulletManager/BulletManager.hpp"
#include "../Enemy/Enemy.hpp"
#include "../DefaultSettings/DefaultSettings.hpp"

class EnemyManager {
 public:
  void AddEnemy(AnimationManager& manager, double x_coord, double y_coord,
                double x_left, double x_right, double x_speed);

  void AddEnemy(const Enemy& enemy);

  void UpdateEnemies(double time, std::list<Bullet*>* bullets);

  void DrawEnemies(sf::RenderWindow& window, double offsetX, double offsetY);

  std::vector<Enemy>& GetEnemies();

  void SetAllDefault();

 private:
  std::vector<Enemy> enemies_;
};

#endif