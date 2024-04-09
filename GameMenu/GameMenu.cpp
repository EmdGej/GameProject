#include "GameMenu.hpp"

GameMenu::GameMenu(const MenuParams& params, const std::vector<std::string>& item_texts, int32_t window_width, int32_t window_height): params_(params) {
    font_.loadFromFile("fonts/font.ttf");
    background_txt_.loadFromFile("background/menu_background.jpg");
    background_.setTexture(background_txt_);

    items_ = std::vector<sf::Text>(item_texts.size());
    double cur_y = params_.y_coord;

    for(size_t i = 0; i < items_.size(); ++i) {
        InitText(items_[i], item_texts[i], params_.x_coord, cur_y);
        cur_y += params_.item_step;
    }



    AlignMenu();
    cur_item_ = 0;
    items_[cur_item_].setFillColor(cur_item_color_);
    sf::Vector2u TextureSize = background_txt_.getSize();

    float ScaleX = (float) window_width / TextureSize.x;
    float ScaleY = (float) window_height / TextureSize.y;

    background_.setTexture(background_txt_);
    background_.setScale(ScaleX, ScaleY); 
}

void GameMenu::DrawMenu(sf::RenderWindow& window) {
    window.draw(background_);
    for(size_t i = 0; i < items_.size(); ++i) {
        window.draw(items_[i]);
    }
}

void GameMenu::MoveUp() {
    items_[cur_item_].setFillColor(item_color_);
    if(cur_item_ == 0) {
        cur_item_ = items_.size() - 1;
    } else {
        --cur_item_;
    }
    items_[cur_item_].setFillColor(cur_item_color_);
}

void GameMenu::MoveDown() {
    items_[cur_item_].setFillColor(item_color_);
    if(cur_item_ == items_.size() - 1) {
        cur_item_ = 0;
    } else {
        ++cur_item_;
    }
    items_[cur_item_].setFillColor(cur_item_color_);
}

sf::Text GameMenu::GetCurItem() const {
    return items_[cur_item_];
}

double GameMenu::GetXCoord() const {
    return params_.x_coord;
}

double GameMenu::GetYCoord() const {
    return params_.y_coord;
}

int32_t GameMenu::GetItemStep() const {
    return params_.item_step;
}

size_t GameMenu::GetFontSize() const {
    return params_.font_size;
}

sf::Font GameMenu::GetFont() const {
    return font_;
}

sf::Color GameMenu::GetItemColor() const {
    return item_color_;
}

sf::Color GameMenu::GetCurItemColor() const {
    return cur_item_color_;
}

sf::Color GameMenu::GetItemBorderColor() const {
    return item_border_color_;
}

void GameMenu::SetXCoord(double x_coord) {
    params_.x_coord = x_coord;
}

void GameMenu::SetYCoord(double y_coord) {
    params_.y_coord = y_coord;
}

void GameMenu::SetItemStep(int32_t item_step) {
    params_.item_step = item_step;
}

void GameMenu::SetFontSize(size_t font_size) {
    params_.font_size = font_size;
}

void GameMenu::SetFont(sf::Font font) {
    font_ = font;
}

void GameMenu::SetItemColor(sf::Color color) {
    item_color_ = color;
}

void GameMenu::SetCurItemColor(sf::Color color) {
    cur_item_color_ = color;
}

void GameMenu::GetItemBorderColor(sf::Color color) {
    item_border_color_ = color;
}