#ifndef GAME
#define GAME

#include "../AnimationLoader/AnimationLoader.hpp"
#include "../Bullet/Bullet.hpp"
#include "../BulletManager/BulletManager.hpp"
#include "../CollisionManager/CollisionManager.hpp"
#include "../ControlManager/ControlManager.hpp"
#include "../Enemy/Enemy.hpp"
#include "../EnemyManager/EnemyManager.hpp"
#include "../Map/Map.hpp"
#include "../MapLoader/MapLoader.hpp"
#include "../Player/Player.hpp"
#include "../GameMenu/GameMenu.hpp"
#include "../MenuManager/MenuManager.hpp"
#include "../SoundsManager/SoundsManager.hpp"
#include "../StaminaBar/StaminaBar.hpp"
#include "../HealthBar/HealthBar.hpp"
class Game {
 public:
  Game(int32_t window_width, int32_t window_height);

  void GameLoop();

 private:
  AnimationManager animation_manager_;
  AnimationLoader animation_loader_;
  BulletManager bullet_manager_;
  EnemyManager enemy_manager_;
  CollisionManager collision_manager_;
  ControlManager control_manager_;
  MenuManager menu_manager_;
  SoundsManager sounds_manager_;


  sf::Sprite background_;
  sf::Texture background_txt_;

  Player player_;
  std::vector<Enemy*> enemies_;
  std::unordered_map<char, std::string> tls_;

  StaminaBar stamina_bar_;
  HealthBar health_bar_;
  
  MapParams map_;
  MapLoader map_loader_;

  sf::Clock clock_;

  std::unordered_set<char> colision_blocks_;
  std::unordered_set<char> die_blocks_;

  int32_t width_;
  int32_t height_;

  double offsetX_ = 0;
  double offsetY_ = 0;
};

#endif