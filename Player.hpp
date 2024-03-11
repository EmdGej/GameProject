/*
Player - класс игрока в игре, унаследованный от базовой сущности AbstractEntity

Конструктор:
  x_coord - координата x,
  y_coord - координата y,
  health - здоровье игрока,
  damage - урон игрока,
  acceleration - ускорение игрока


Поля: (часть унаследована от AbstractEntity)
  enum {stay, run, jump, slide, climb} STATE - возможные состояния игрока
  std::unordered_map<std::string, bool> keys_ - состояния используемых в игре
кнопок double acceleration_ - ускорение игрока bool direction_ = false; // 0 -
left, 1 - right - направление движения игрока const double kSpeedX = 0.2 -
стандартная скорость игрока по x const double kSpeedY = 0.5 - стандартная
скорость игрока по y

  bool prev_direction = false; // 0 - left, 1 - right - отслеживание
одновременных нажатий


Методы:
  UpdatePlayer - обновление анимации и положения игрока

  SetState - устанавливает текущее состояние игрока

  UpdateKeys - обновляет нажатые кнопки

  ResetKeys - сбрасывает состояния нажатых кнопок

  FillMapWithKeys - заполняет map используемыми кнопками
*/

#include "AbstractEntity.hpp"

class Player : public AbstractEntity {
 public:
  Player(double x_coord, double y_coord, int32_t health, int32_t damage,
         double acceleration = 0.005);

  void UpdatePlayer(AnimationManager& manager, double time);

  void SetKeys(std::string key, bool flag);

  double GetXCoord();

  double GetYCoord();

  void SetDoubleJumpAbility(bool ability);

 private:
  enum { stay, run, jump, slide, climb } STATE;
  std::unordered_map<std::string, bool> keys_;

  double acceleration_ = 0;

  bool direction_ = false;     // 0 - left, 1 - right
  bool both_pressed_ = false;  // 0 - left, 1 - right

  const double kSpeedX = 0.2;
  const double kSpeedY = 2;

  double stamina_ = 100;
  const double kStaminaCoef = 2;
  const double kStaminaLoss = 0.015;
  const double kStaminaGet = 0.008;
  const double kTimeToRestoreStamina = 2;

  sf::Clock time_from_last_stamina_usage_;

  bool is_double_jump_available_ = false;
  bool was_jump_pressed_ = false;
  bool has_double_jump_ = false;

  void SetState(AnimationManager& manager) {
    if (STATE == stay) {
      manager.SetAnimation("stay");
    }

    if (STATE == run) {
      manager.SetAnimation("run");
    }

    if (STATE == jump) {
      manager.SetAnimation("jump");
    }

    if (STATE == slide) {
      manager.SetAnimation("slide");
    }

    if (STATE == climb) {
      manager.SetAnimation("climb");
    }

    if (is_shooting_) {
      if (STATE == stay) {
        manager.SetAnimation("stay_shoot");
      }

      if (STATE == run) {
        manager.SetAnimation("run_shoot");
      }

      if (STATE == jump) {
        manager.SetAnimation("jump_shoot");
      }
    }
  }

  void UpdateKeys(double time) {
    //============================== STAY ============================== //
    if (!(keys_["ArrowLeft"]) && !(keys_["ArrowRight"])) {
      if (is_on_ground_) {
        STATE = stay;
      }

      x_speed_ = 0;
    }

    //============================== RUN ============================== //
    if (keys_["ArrowLeft"] && keys_["ArrowRight"]) {
      if (!both_pressed_) {
        direction_ = !direction_;

        if (keys_["Shift"] && stamina_ > 0) {
          time_from_last_stamina_usage_.restart();
          x_speed_ = (x_speed_ > 0 ? -kSpeedX : kSpeedX) * kStaminaCoef;
          stamina_ -= kStaminaLoss * time;
        } else {
          x_speed_ = (x_speed_ > 0 ? -kSpeedX : kSpeedX);
        }
      } else {
        if (keys_["Shift"] && stamina_ > 0) {
          time_from_last_stamina_usage_.restart();
          x_speed_ = (x_speed_ > 0 ? kSpeedX : -kSpeedX) * kStaminaCoef;
          stamina_ -= kStaminaLoss * time;
        }
      }
      if (is_on_ground_) {
        STATE = run;
      }
      both_pressed_ = true;
    } else if (keys_["ArrowLeft"]) {
      if (STATE == stay) {
        STATE = run;
      }
      if (keys_["Shift"] && stamina_ > 0) {
        time_from_last_stamina_usage_.restart();
        x_speed_ = -kSpeedX * kStaminaCoef;
        stamina_ -= kStaminaLoss * time;
      } else {
        x_speed_ = -kSpeedX;
      }

      both_pressed_ = false;
      direction_ = 0;
    } else if (keys_["ArrowRight"]) {
      if (STATE == stay) {
        STATE = run;
      }
      if (keys_["Shift"] && stamina_ > 0) {
        time_from_last_stamina_usage_.restart();
        x_speed_ = kSpeedX * kStaminaCoef;
        stamina_ -= kStaminaLoss * time;
      } else {
        x_speed_ = kSpeedX;
      }

      both_pressed_ = false;
      direction_ = 1;
    }

    //============================== JUMP ============================== //
    if (keys_["Z"] && is_double_jump_available_) {
      if (STATE == jump && !was_jump_pressed_) {
        y_speed_ = -kSpeedY;
        is_double_jump_available_ = false;
        is_on_ground_ = false;
      }
    }
    
    if (keys_["Z"]) {
      if (STATE == stay || STATE == run || STATE == slide || STATE == climb) {
        STATE = jump;

        y_speed_ = -kSpeedY;

        is_on_ground_ = false;
        was_jump_pressed_ = true;
      }
    }

    //============================== SHOOT ============================== //
    if (keys_["X"]) {
      is_shooting_ = true;
    }

    if (!keys_["X"]) {
      is_shooting_ = false;
    }

    if(!keys_["Z"]) {
      was_jump_pressed_ = false;
    }

    if (((!keys_["Shift"] && stamina_ < 100) ||
         (keys_["Shift"] && stamina_ < 100 && x_speed_ == 0))) {
      if (time_from_last_stamina_usage_.getElapsedTime().asSeconds() >=
          kTimeToRestoreStamina) {
        stamina_ += kStaminaGet * time;
      }
    }
  }

  void ResetKeys() {
    for (auto& key_state : keys_) {
      key_state.second = false;
    }
  }

  // X - стрельба, Z - прыжок, C - опциональное, Shift - ускоренный бег
  void FillMapWithKeys() {
    std::vector<std::string> keys = {"ArrowLeft", "ArrowLeft", "ArrowUp",
                                     "ArrowDown", "Space",     "Z",
                                     "X",         "C",         "Shift"};

    for (size_t i = 0; i < keys.size(); ++i) {
      keys_[keys[i]] = false;
    }
  }
};