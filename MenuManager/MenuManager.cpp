#include "MenuManager.hpp"

MenuManager::MenuManager() {
    cur_menu_ = "main menu";
    is_menu_ = true;
    FillMapWithKeys();
}

MenuManager::~MenuManager() {
    for(auto& elem: menus_) {
        delete elem.second;
    }
}

void MenuManager::AddMenu(const std::string& name, GameMenu* menu) {
    menus_[name] =  menu;
}

void MenuManager::UpdateCurMenu(sf::RenderWindow& window, Player& player, EnemyManager& enemy_manager, double x_coord, double y_coord) {
    if(keys_["Up"]) {
        menus_[cur_menu_]->MoveUp();
    }
    if(keys_["Down"]) {
        menus_[cur_menu_]->MoveDown();
    }
    if(keys_["Enter"]) {
        if(cur_menu_ == "main menu") {
            if(menus_[cur_menu_]->GetCurItem().getString() == "Exit") {
                window.close();
            }
            if(menus_[cur_menu_]->GetCurItem().getString() == "Start") {
                is_menu_ = false;
                player.SetDefault();
                player.SetXCoord(x_coord);
                player.SetYCoord(y_coord);
                enemy_manager.SetAllDefault();
            }
        }
        if(cur_menu_ == "restart menu") {
            if(menus_[cur_menu_]->GetCurItem().getString() == "Continue") {
                is_menu_ = false;
            }

            if(menus_[cur_menu_]->GetCurItem().getString() == "Main Menu") {
                cur_menu_ = "main menu";
            }
            if(menus_[cur_menu_]->GetCurItem().getString() == "Restart")    {
                player.SetDefault();
                enemy_manager.SetAllDefault();
                is_menu_ = false;
            }    
        }
    }
    FillMapWithKeys();
}

void MenuManager::DrawCurMenu(sf::RenderWindow& window) {
    menus_[cur_menu_]->DrawMenu(window);
}

void MenuManager::SetIsMenu(bool flag) {
    is_menu_ = flag;
}

bool MenuManager::GetIsMenu() const {
    return is_menu_;
}

void MenuManager::SetCurMenu(const std::string& name) {
    cur_menu_ = name;
}

GameMenu* MenuManager::GetCurMenu() {
    return menus_[cur_menu_];
}

std::string MenuManager::GetCurName() const {
    return cur_menu_;
}

void MenuManager::SetKeys(std::string key, bool flag) {
    keys_[key] = flag;
}