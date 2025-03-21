#ifndef ABSTRACT_ENTITY
#define ABSTRACT_ENTITY

#include <unordered_map>
#include <vector>

#include "../AnimationManager/AnimationManager.hpp"

class AbstractEntity {
 protected:
  double x_speed_ = 0;
  double y_speed_ = 0;

  double x_coord_ = 0;
  double y_coord_ = 0;

  int32_t damage_ = 0;

  bool is_shooting_ = false;
  bool is_on_ground_ = false;
  bool is_on_ladder_ = false;
  bool is_hitted_ = false;

  int32_t health_ = 100;
};

#endif