#include "ControlManager.hpp"

void ControlManager::ControlKeyboard(Player& player) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    player.SetKeys("ArrowLeft", true);
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    player.SetKeys("ArrowRight", true);
  } 

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
    player.SetKeys("Z", true);
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
    player.SetKeys("Shift", true);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
    player.SetKeys("X", true);
  }
}  
