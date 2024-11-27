#include "HealthBar.hpp"

HealthBar::HealthBar(float length, float height, float x, float y) {
  max_length_= length;
  max_height_= height;
  x_position_ = x;
  y_position_ = y;

  health_bar_rect_.setFillColor(sf::Color(199, 52, 52));
  health_bar_rect_.setSize(sf::Vector2f(max_length_, max_height_));

  coverage_bar_.setFillColor(sf::Color(0, 0, 0));
}

HealthBar::HealthBar(const std::string& health_bar_path, float length, float height, float x, float y) {
  max_length_= length;
  max_height_= height;
  x_position_ = x;
  y_position_ = y;

  sf::Texture health_bar_texture;
  health_bar_texture.loadFromFile(health_bar_path);

  health_bar_.setTexture(health_bar_texture);

  coverage_bar_.setFillColor(sf::Color(0, 0, 0));

  is_image_ = true;
}

void HealthBar::UpdateHealthBar(const Player& player) {
  if (player.GetHealth() >= 0 && player.GetHealth() <= 100) {
    coverage_bar_.setSize(sf::Vector2f(-max_length_ * (1 - player.GetHealth() / 100), max_height_));
  }
}

void HealthBar::DrawHealthBar(sf::RenderWindow& window) {
  sf::Vector2f center = window.getView().getCenter();
  sf::Vector2f size = window.getView().getSize();

  health_bar_.setPosition(x_position_, y_position_);

  health_bar_rect_.setPosition(x_position_, y_position_);
  coverage_bar_.setPosition(x_position_ + max_length_, y_position_);

  if (is_image_) {
    window.draw(health_bar_);
  } else {
    window.draw(health_bar_rect_);
  }
    
  window.draw(coverage_bar_);
}