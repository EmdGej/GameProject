#include "StaminaBar.hpp"

StaminaBar::StaminaBar(float length, float height, float x, float y) {
  max_length_= length;
  max_height_= height;
  x_position_ = x;
  y_position_ = y;

  stamina_bar_rect_.setFillColor(sf::Color(85, 29, 207));
  stamina_bar_rect_.setSize(sf::Vector2f(max_length_, max_height_));

  coverage_bar_.setFillColor(sf::Color(0, 0, 0));
}

StaminaBar::StaminaBar(const std::string& stamina_bar_path, float length, float height, float x, float y) {
  max_length_= length;
  max_height_= height;
  x_position_ = x;
  y_position_ = y;

  sf::Texture stamina_bar_texture;
  stamina_bar_texture.loadFromFile(stamina_bar_path);

  stamina_bar_.setTexture(stamina_bar_texture);

  coverage_bar_.setFillColor(sf::Color(0, 0, 0));

  is_image_ = true;
}

void StaminaBar::UpdateStaminaBar(const Player& player) {
  if (player.GetStamina() >= 0 && player.GetStamina() <= player.GetMaxStamina()) {
    coverage_bar_.setSize(sf::Vector2f(-max_length_ * (1 - player.GetStamina() / player.GetMaxStamina()), max_height_));
  }
}

void StaminaBar::DrawStaminaBar(sf::RenderWindow& window) {
  sf::Vector2f center = window.getView().getCenter();
  sf::Vector2f size = window.getView().getSize();

  stamina_bar_.setPosition(x_position_, y_position_);

  stamina_bar_rect_.setPosition(x_position_, y_position_);
  coverage_bar_.setPosition(x_position_ + max_length_, y_position_);

  if (is_image_) {
    window.draw(stamina_bar_);
  } else {
    window.draw(stamina_bar_rect_);
  }
    
  window.draw(coverage_bar_);
}