#include "BulletManager.hpp"

void BulletManager::AddBullet(AnimationManager manager, double bullet_speed,
                              bool player_direction, double player_x,
                              double player_y, double player_width,
                              double player_height, int32_t player_health) {
  if (player_health <= 0) {
    return;
  }

  if (player_direction) {
    bullets_.push_back(new Bullet(manager, player_x + player_width,
                                  player_y + player_height / 2, bullet_speed,
                                  player_direction));
  } else {
    bullets_.push_back(new Bullet(manager, player_x - player_width / 2,
                                  player_y + player_height / 2, bullet_speed,
                                  player_direction));
  }
}

void BulletManager::CheckLifeBullets() {
  for (auto it = bullets_.begin(); it != bullets_.end();) {
    Bullet* bullet = *it;

    if (bullet->GetIsAlive() == false) {
      it = bullets_.erase(it);
      delete bullet;
    } else {
      it++;
    }
  }
}

void BulletManager::UpdateDrawBullets(sf::RenderWindow& window,
                                      const MapParams& map_params,
                                      const std::unordered_set<char>& blocks,
                                      double time, double offsetX,
                                      double offsetY) {
  for (auto it = bullets_.begin(); it != bullets_.end(); it++) {
    (*it)->UpdateBullet(map_params, blocks, time);
    (*it)->DrawBullet(window, offsetX, offsetY);
  }
}

std::list<Bullet*>* BulletManager::GetBulletsList() { return &bullets_; }

void BulletManager::Clear() {
  for (auto bullet : bullets_) {
    delete bullet;
  }

  bullets_.clear();
}

BulletManager::~BulletManager() {
  for (auto bullet : bullets_) {
    delete bullet;
  }
}