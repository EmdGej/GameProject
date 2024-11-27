#ifndef STAMINA_BAR
#define STAMINA_BAR

#include <SFML/Graphics.hpp>
#include "../Player/Player.hpp"

class StaminaBar {
 public:
  StaminaBar() = default;

  StaminaBar(float length, float height, float x, float y);

  StaminaBar(const std::string& stamina_bar_path, float length, float height, float x, float y);

  void UpdateStaminaBar(const Player& player);

  void DrawStaminaBar(sf::RenderWindow& window);

 private:
  sf::Sprite stamina_bar_;
  
  sf::RectangleShape stamina_bar_rect_;
  sf::RectangleShape coverage_bar_;

  float max_length_;
  float max_height_;
  float x_position_;
  float y_position_;

  bool is_image_ = false;
};

#endif