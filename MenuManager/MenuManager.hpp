#ifndef MENU_MANAGER
#define MENU_MANAGER

#include "../GameMenu/GameMenu.hpp"
#include "../Player/Player.hpp"
#include "../EnemyManager/EnemyManager.hpp"
#include <unordered_map>

class MenuManager {
    public:
    MenuManager();

    ~MenuManager();

    void AddMenu(const std::string& name, GameMenu* menu);

    void UpdateCurMenu(sf::RenderWindow& window, Player& player, EnemyManager& enemy_manager);

    void DrawCurMenu(sf::RenderWindow& window);

    void SetIsMenu(bool flag);

    bool GetIsMenu() const;

    void SetCurMenu(const std::string& name);

    GameMenu* GetCurMenu();

    std::string GetCurName() const;

    void SetKeys(std::string key, bool flag);

    private:
    bool is_menu_ = true;
    std::unordered_map<std::string, bool> keys_;
    std::unordered_map<std::string, GameMenu*> menus_;
    std::string cur_menu_ = "main menu";
    
    void FillMapWithKeys() {
        std::vector<std::string> keys = {"Up", "Down", "Enter",
                                        "Escape"};

        for (size_t i = 0; i < keys.size(); ++i) {
        keys_[keys[i]] = false;
        }
    }
};

#endif