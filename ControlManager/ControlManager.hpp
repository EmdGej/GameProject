#ifndef CONTROL_MANAGER
#define CONTROL_MANAGER

#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "../Player/Player.hpp"

class ControlManager {
 public:
  void ControlKeyboard(Player& player);
};

#endif