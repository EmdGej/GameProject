#include "Game.hpp"

Game::Game(int32_t window_width, int32_t window_height)
    : width_(window_width),
      height_(window_height),
      animation_loader_(animations),
      map_(MapParams{tilemap, "lvl1", Height, Width, 32}) {
  background_txt_.loadFromFile("background/background.png");
  background_.setTexture(background_txt_);
  animation_loader_.LoadSprites(animation_manager_);

  player_ = Player(animation_manager_, 300, 700, 100, 1, 0.0015);
  player_.SetDoubleJumpAbility(true);
  player_.SetSpeedY(0.6);
  player_.SetCurXSpeed(0.25);

  tls_['B'] = "tiles/B.png";
  tls_['F'] = "tiles/F.png";
  tls_['S'] = "tiles/S.png";
  tls_['V'] = "tiles/V.png";
  tls_['H'] = "tiles/H.png";
  tls_['R'] = "tiles/R.png";

  map_loader_.DownloadMap(tilemap, "lvl1", tls_, Height, Width, 32);

  colision_blocks_ = {'B', 'F'};
  die_blocks_ = {'S'};
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

  // ============================== Game Cylce ============================== //
  sf::RenderWindow window_(sf::VideoMode(width_, height_), "Game");
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
        if (event.key.code == sf::Keyboard::X) {
          player_.SetKeys("X", true);
          bullet_manager_.AddBullet(
              animation_manager_, 0.5, player_.GetDirection(),
              player_.GetXCoord(), player_.GetYCoord(),
              player_.GetAnimationWidth(), player_.GetAnimationHeight(),
              player_.GetHealth());
        }
      }
    }

    control_manager_.ControlKeyboard(player_);

    offsetX_ = player_.GetXCoord() - width_ / 2;
    offsetY_ = player_.GetYCoord() - height_ / 2;

    window_.clear(sf::Color::White);

    window_.draw(background_);

    map_loader_.DrawMap(window_, offsetX_, offsetY_);

    player_.UpdatePlayer(map_, colision_blocks_, die_blocks_, time);
    player_.DrawPlayer(window_, offsetX_, offsetY_);

    enemy_manager_.UpdateEnemies(time, bullet_manager_.GetBulletsList());
    enemy_manager_.DrawEnemies(window_, offsetX_, offsetY_);

    bullet_manager_.CheckLifeBullets();
    bullet_manager_.UpdateDrawBullets(window_, map_, colision_blocks_, time,
                                      offsetX_, offsetY_);

    collision_manager_.CheckCollisions(player_, enemy_manager_.GetEnemies());

    window_.display();
  }
}