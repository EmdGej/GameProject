#ifndef BULLET
#define BULLET

#include <unordered_set>

#include "AnimationManager.hpp"
#include "MapLoader.hpp"

class Bullet {
 public:
  Bullet(AnimationManager manager, double x_coord, double y_coord,
         double x_speed, bool direction);

  void UpdateBullet(const MapParams& map_params,
                    const std::unordered_set<char>& blocks, double time);

  void DrawBullet(sf::RenderWindow& window, double offsetX, double offsetY);

  double GetXCoord() const;
  double GetYCoord() const;

  double GetXSpeed() const;
  bool GetIsAlive() const;

  void SetXSpeed(double value);

 private:
  AnimationManager manager_;
  double x_coord_;
  double y_coord_;
  double x_speed_ = 0.1;
  bool direction_;
  bool is_alive_ = true;

  void CheckBlocksCollision(const MapParams& map_params,
                            const std::unordered_set<char>& blocks) {
    for (int32_t i = y_coord_ / map_params.tile_size;
         i < (y_coord_ + manager_.GetAnimationHeight()) / map_params.tile_size;
         ++i) {
      for (int32_t j = x_coord_ / map_params.tile_size;
           j < (x_coord_ + manager_.GetAnimationWidth()) / map_params.tile_size;
           ++j) {
        if (blocks.find(map_params.map[i][j]) != blocks.end()) {
          is_alive_ = false;
          x_speed_ = 0;
        }
      }
    }
  }
};

#endif