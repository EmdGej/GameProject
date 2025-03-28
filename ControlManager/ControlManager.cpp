#include "ControlManager.hpp"

void ControlManager::ControlKeyboard(Player& player, MenuManager& menu_manager, SoundsManager& sounds_manager) {
  if(!menu_manager.GetIsMenu()) {    
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

  } else {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
      menu_manager.SetKeys("Up", true);
      sounds_manager.PlaySound("menu_select");
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
      menu_manager.SetKeys("Down", true);
      sounds_manager.PlaySound("menu_select");
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
      menu_manager.SetKeys("Enter", true);
      sounds_manager.PlaySound("game_start");
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
      menu_manager.SetKeys("Escape", true);
    }
  }
}
