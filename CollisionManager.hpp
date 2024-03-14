#ifndef COLLISION_MANAGER
#define COLLISION_MANAGER


#include "Player.hpp"
#include "Enemy.hpp"

class CollisionManager {
 public:
  void CheckCollisions(Player& player, std::vector<Enemy>& enemies);
};

#endif
