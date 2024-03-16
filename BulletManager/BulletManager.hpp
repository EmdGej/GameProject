#ifndef BULLET_MANAGER
#define BULLET_MANAGER

#include <list>

#include "../AnimationManager/AnimationManager.hpp"
#include "../Bullet/Bullet.hpp"
#include "../MapLoader/MapLoader.hpp"

class BulletManager {
 public:
  void AddBullet(AnimationManager manager, double bullet_speed,
                 bool player_direction, double player_x, double player_y,
                 double player_width, double player_height, int32_t player_health);

  void CheckLifeBullets();

  void UpdateDrawBullets(sf::RenderWindow& window, const MapParams& map_params,
                         const std::unordered_set<char>& blocks, double time, 
                         double offsetX, double offsetY);

  std::list<Bullet*>* GetBulletsList();

 private:
  std::list<Bullet*> bullets_;
};

#endif