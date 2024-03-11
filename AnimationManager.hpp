#ifndef ANIMATION_MANAGER
#define ANIMATION_MANAGER

#include "Animation.hpp"

/*
AnimationManager - главный класс для отрисовки анимации объектов в игре. В нем
хранится map названий анимаций и объектов типа Animation.

Конструктор default


Поля:
    current_animation_ - название текущей анимации, которая будет отрисована
(например, "animation_run") animations_list_ - map: название анимации - объект
Animation, отвечающий за эту анимацию


Методы:
    Create(const std::string& animation_name, const std::vector<sf::Texture>&
textures, double play_speed, int32_t scale) - добавляет в map анимацию Animation
и устанавливает ее текущей


    !!! UpdateFrame(double time) - обновляет анимацию
    !!! Draw(sf::RenderWindow& window, int32_t x = 0, int32_t y = 0) - рисует
текущую анимацию Animation в координатах x, y на окне window

    SetAnimation(const std::string animation_name) - устанавливает текущей
анимацию animation_name

    SetFlip(bool flip) - устанавливает, нужно ли отображать анимацию зеркально

    SetAnimationPause() / SetAnimationPlay() - ставит отрисовку на паузу /
возобнавляет отрисовку (опционально)


*/

class AnimationManager {
 public:
  void Create(std::string animation_name,
              const std::vector<sf::Texture>& textures, double play_speed,
              int32_t scale);

  void Draw(sf::RenderWindow& window, int32_t x = 0, int32_t y = 0);

  void SetAnimation(std::string animation_name);

  void SetFlip(bool flip);

  void UpdateFrame(double time);

  void SetAnimationPause();

  void SetAnimationPlay();

  int32_t GetAnimationHeight();
  int32_t GetAnimationWidth();

 private:
  std::string current_animation_;
  std::unordered_map<std::string, Animation> animations_list_;
};

#endif