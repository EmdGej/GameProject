#include "Game.hpp"

Game::Game(int32_t window_width, int32_t window_height)
    : width_(window_width),
      height_(window_height),
      animation_loader_(animations),
      map_(MapParams{tilemap, "lvl1", Height, Width, 32}) {
  background_txt_.loadFromFile("background/background.png");

  checkpoint_manager_.LoadState();

  sf::Vector2u TextureSize = background_txt_.getSize();

  float ScaleX = (float) window_width / TextureSize.x;
  float ScaleY = (float) window_height / TextureSize.y;

  background_.setTexture(background_txt_);
  background_.setScale(ScaleX, ScaleY); 

  animation_loader_.LoadSprites(animation_manager_);

  player_ = Player(animation_manager_, checkpoint_manager_.GetX(), checkpoint_manager_.GetY(), 100, 1, 0.0015);
  player_.SetDoubleJumpAbility(true);
  player_.SetSpeedY(0.6);
  player_.SetCurXSpeed(0.25);

  MenuParams params = {window_width/2.0, 0.3 * window_height, 150, 150};

  GameMenu* main_menu = new GameMenu(params, {"Start", "Exit"}, window_width, window_height);
  GameMenu* restart_menu = new GameMenu(params, {"Continue", "Restart", "Main Menu"}, window_width, window_height);

  menu_manager_.AddMenu("main menu", main_menu);
  menu_manager_.AddMenu("restart menu", restart_menu);

  health_bar_ = HealthBar(300, 30, 20, 20);
  stamina_bar_ = StaminaBar(300, 30, 20, 70);

  tls_['B'] = "tiles/B.png";
  tls_['F'] = "tiles/F.png";
  tls_['S'] = "tiles/S.png";
  tls_['V'] = "tiles/V.png";
  tls_['H'] = "tiles/H.png";
  tls_['R'] = "tiles/R.png";
  tls_['C'] = "tiles/C.png";

  map_loader_.DownloadMap(tilemap, "lvl1", tls_, Height, Width, 32);

  colision_blocks_ = {'B', 'F'};
  die_blocks_ = {'S', 'R'};

  sounds_manager_.LoadSounds({{"menu_select", "sounds/menu_select.ogg"},
                              {"game_start", "sounds/game_start.ogg"},
                              {"jump", "sounds/jump.ogg"},
                              {"shoot", "sounds/shoot.ogg"},
                              {"pause_menu", "sounds/pause_menu.ogg"},
                              {"die", "sounds/die.ogg"}});
  
  sounds_manager_.LoadMusics({{"game_music", "music/game_music.ogg"}}, {1});
}

void Game::GameLoop() {

  // ============================== Create Enemies
  // ============================== //
  Enemy enemy1(animation_manager_, 4195, 1034, 4195, 4320, 0.1);
  Enemy enemy2(animation_manager_, 2150, 650, 2000, 2300, 0.1);
  Enemy enemy3(animation_manager_, 4192, 1356, 4191, 4360, 0.1);
  Enemy enemy4(animation_manager_, 4350, 1356, 4191, 4360, 0.1);

  enemy_manager_.AddEnemy(enemy1);
  enemy_manager_.AddEnemy(enemy2);
  enemy_manager_.AddEnemy(enemy3);
  enemy_manager_.AddEnemy(enemy4);

  bool game_music_playing = false;
  bool has_player_died = false;

  // ============================== Game Cylce ============================== //
  sf::RenderWindow window_(sf::VideoMode(width_, height_), "Game");
  
  window_.setKeyRepeatEnabled(false);

  while (window_.isOpen()) {
    float time = clock_.getElapsedTime().asMicroseconds();
    clock_.restart();
    time = time / 500;
    sf::Event event;

    while (window_.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window_.close();
      }

      if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::X && !menu_manager_.GetIsMenu()) {
          player_.SetKeys("X", true);
          
          bullet_manager_.AddBullet(
              animation_manager_, 0.5, player_.GetDirection(),
              player_.GetXCoord(), player_.GetYCoord(),
              player_.GetAnimationWidth(), player_.GetAnimationHeight(),
              player_.GetHealth());

              if (player_.GetHealth() != 0) {
                sounds_manager_.PlaySound("shoot");
              }
        }

        if (event.key.code == sf::Keyboard::R && !menu_manager_.GetIsMenu()) {
          enemy_manager_.SetAllDefault();
          player_.SetDefault();
          player_.SetXCoord(checkpoint_manager_.GetX());
          player_.SetYCoord(checkpoint_manager_.GetY());


          game_music_playing = false;
          has_player_died = false;

          bullet_manager_.Clear();
        }

        if (event.key.code == sf::Keyboard::Escape && !menu_manager_.GetIsMenu()) {
          menu_manager_.SetIsMenu(true);
          menu_manager_.SetCurMenu("restart menu");
          sounds_manager_.PlaySound("pause_menu");
        }

        if(menu_manager_.GetIsMenu()) {
          control_manager_.ControlKeyboard(player_, menu_manager_, sounds_manager_);
          menu_manager_.UpdateCurMenu(window_, player_, enemy_manager_, checkpoint_manager_.GetX(), checkpoint_manager_.GetY());
        }
      }
    }

    if(menu_manager_.GetIsMenu()) {
      if (game_music_playing) {
        sounds_manager_.StopMusic("game_music");
        game_music_playing = false;
      }
      
      bullet_manager_.Clear();
      menu_manager_.DrawCurMenu(window_);

      game_music_playing = false;
      has_player_died = false;
    } else {
      if (player_.GetHealth() == 0) {
        if (game_music_playing) {
          sounds_manager_.StopMusic("game_music");
          game_music_playing = false;
        }
         
        game_music_playing = false;

        if (!has_player_died) {
          sounds_manager_.PlaySound("die");
          has_player_died = true;
        }
      }

      if (!game_music_playing && player_.GetHealth() != 0) {
        sounds_manager_.PlayMusic("game_music");
        game_music_playing = true;
      }
       
      control_manager_.ControlKeyboard(player_, menu_manager_, sounds_manager_);

      offsetX_ = player_.GetXCoord() - width_ / 2;
      offsetY_ = player_.GetYCoord() - height_ / 2;

      window_.clear(sf::Color::White);

      window_.draw(background_);

      map_loader_.DrawMap(window_, offsetX_, offsetY_);

      player_.UpdatePlayer(map_, colision_blocks_, die_blocks_, time);
      player_.DrawPlayer(window_, offsetX_, offsetY_);

      checkpoint_manager_.CheckCollision(player_, map_);

      enemy_manager_.UpdateEnemies(time, bullet_manager_.GetBulletsList());
      enemy_manager_.DrawEnemies(window_, offsetX_, offsetY_);

      bullet_manager_.CheckLifeBullets();
      bullet_manager_.UpdateDrawBullets(window_, map_, colision_blocks_, time,
                                        offsetX_, offsetY_);

      collision_manager_.CheckCollisions(player_, enemy_manager_.GetEnemies());

      health_bar_.UpdateHealthBar(player_);
      health_bar_.DrawHealthBar(window_);
      
      stamina_bar_.UpdateStaminaBar(player_);
      stamina_bar_.DrawStaminaBar(window_);

    }
    window_.display();
  }
}