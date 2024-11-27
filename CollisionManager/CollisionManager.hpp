#ifndef COLLISION_MANAGER
#define COLLISION_MANAGER

#include "../Enemy/Enemy.hpp"
#include "../Player/Player.hpp"

class CollisionManager {
 public:
  void CheckCollisions(Player& player, std::vector<Enemy>& enemies);
};

#endif
