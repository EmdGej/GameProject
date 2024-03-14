#include "CollisionManager.hpp"

void CollisionManager::CheckCollisions(Player& player, std::vector<Enemy>& enemies) {
  for (auto& enemy: enemies) {
    if (sf::Rect<double>(player.GetXCoord(), player.GetYCoord(), player.GetAnimationWidth(), player.GetAnimationHeight()).intersects(sf::Rect<double>(enemy.GetXCoord(), enemy.GetYCoord(), enemy.GetAnimationWidth(), enemy.GetAnimationHeight()))) {
      player.SetHealth(0);
      return;
    }
  }
}
