#ifndef GAME_MENU
#define GAME_MENU

#include <SFML/Graphics.hpp>
#include <vector>
#include "../DefaultSettings/DefaultSettings.hpp"

struct MenuParams {
    double x_coord;
    double y_coord;
    int32_t item_step;
    int32_t font_size;
};

class GameMenu {
    public:
    GameMenu() = default;
    GameMenu(const MenuParams& params, const std::vector<std::string>& item_texts, int32_t window_width, int32_t window_height);

    void DrawMenu(sf::RenderWindow& window);

    void MoveUp();

    void MoveDown();

    sf::Text GetCurItem() const;

    double GetXCoord() const;

    double GetYCoord() const;

    int32_t GetItemStep() const;

    size_t GetFontSize() const;

    sf::Font GetFont() const;

    sf::Color GetItemColor() const;

    sf::Color GetCurItemColor() const;

    sf::Color GetItemBorderColor() const;

    void SetXCoord(double x_coord);

    void SetYCoord(double y_coord);

    void SetItemStep(int32_t item_step);

    void SetFontSize(size_t font_size);

    void SetFont(sf::Font font);

    void SetItemColor(sf::Color color);

    void SetCurItemColor(sf::Color color);

    void GetItemBorderColor(sf::Color color);

    private:
    void AlignMenu() {
        for(size_t i = 0; i < items_.size(); ++i) {
            float aligned_x = items_[i].getLocalBounds().width / 2;
            items_[i].setPosition(items_[i].getPosition().x - aligned_x, items_[i].getPosition().y);
        }
    }

    MenuParams params_;

    size_t cur_item_;

    sf::Font font_;
    std::vector<sf::Text> items_;

    sf::Color item_color_ = sf::Color::White;
    sf::Color cur_item_color_ = sf::Color::Blue;
    sf::Color item_border_color_ = sf::Color::Black;

    size_t border_size_ = 3;

    sf::Sprite background_;
    sf::Texture background_txt_;

    void InitText(sf::Text& text, std::string text_str, float x_coord, float y_coord) {
        text.setFont(font_);
        text.setFillColor(item_color_);
        text.setString(text_str);
        text.setCharacterSize(params_.font_size);
        text.setPosition(x_coord, y_coord);
        text.setOutlineThickness(border_size_);        
        text.setOutlineColor(item_border_color_);        
    }
};

#endif