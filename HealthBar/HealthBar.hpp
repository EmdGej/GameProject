#ifndef HEALTH_BAR
#define HEALTH_BAR

#include <SFML/Graphics.hpp>
#include "../Player/Player.hpp"

class HealthBar {
 public:
  HealthBar() = default;

  HealthBar(float length, float height, float x, float y);

  HealthBar(const std::string& health_bar_path, float length, float height, float x, float y);

  void UpdateHealthBar(const Player& player);

  void DrawHealthBar(sf::RenderWindow& window);

 private:
  sf::Sprite health_bar_;
  
  sf::RectangleShape health_bar_rect_;
  sf::RectangleShape coverage_bar_;

  float max_length_;
  float max_height_;
  float x_position_;
  float y_position_;

  bool is_image_ = false;
};

#endif