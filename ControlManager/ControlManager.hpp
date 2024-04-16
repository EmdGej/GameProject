#ifndef CONTROL_MANAGER
#define CONTROL_MANAGER

#include <SFML/Graphics.hpp>
#include <unordered_map>

#include "../MenuManager/MenuManager.hpp"
#include "../Player/Player.hpp"

class ControlManager {
 public:
  void ControlKeyboard(Player& player, MenuManager& menu_manager);
};

#endif