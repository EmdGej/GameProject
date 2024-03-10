/*
Animation - класс, отвечающий за отрисовку анимации объекта.

Конструкторы:
  1. Animation() = default; -> Default constructor
  2. Animation(const std::vector<sf::Texture>& textures, double play_speed,
int32_t scale): textures_(textures), play_speed_(play_speed), scale_(scale) {}

    textures - массив текстур для текущей анимации (например, массив текстур
бега персонажа) play_speed - скорость отрисовки анимации на окне scale - масштаб
отображения объекта на окне


Поля:
  textures_ - массив полученных из конструктора текстур
  frames_ - массив (размера textures_.size()) прямоугольников, где i-ый
прямоугольник имеет размер i-ой текстуры frames_flip_ - зеркально отраженные
прямоугольники из массива frames_ (нужны для зеркальной отрисовки анимации)

  current_frame_ - текущий фрейм для отрисовки (т.е текстура из массива
textures_) play_speed_ - скорость отрисовки анимации на окне

  flip_ - false, если анимацию нужно отрисовывать нормально, true - если
зеркально is_playing_ - true, если анимацию нужно отрисовывать, false - иначе

  scale_ - масштаб отображения объекта на окне

  sprite_ - текущий объект (текстура + прямоугольник)


Методы:
  1. Getter / Setter для всех полей класса

  2. UpdateFrame(double time) - главный метод класса - отрисовка анимации путем
смены текстур; time - время, необходимое для адаптации одинаковой отрисовки на
разных устройствах

  3. SetSpritePosition(int32_t x, int32_t y) - устанавливает положение объекта в
координаты x, y на окне

  4. DrawSpriteOnWindow(sf::RenderWindow& window) - рисует объект на окне window
*/

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>

class Animation {
 public:
  Animation();

  Animation(const std::vector<sf::Texture>& textures, double play_speed,
            int32_t scale);

  void UpdateFrame(double time);

  void SetSpritePosition(int32_t x, int32_t y);

  void DrawSpriteOnWindow(sf::RenderWindow& window);

  // =========== GETTERS ============ //

  double GetCurrentFrame() const;

  double GetPlaySpeed() const;

  bool GetFlip() const;

  bool GetIsPlaying() const;

  int32_t GetScale() const;

  // =========== SETTERS ============ //

  void SetCurrentFrame(double current_frame);
  void SetPlaySpeed(double play_speed);

  void SetFlip(bool flip);

  void SetIsPlaying(bool is_playing);

  void SetScale(int32_t scale);

 private:
  std::vector<sf::IntRect> frames_;
  std::vector<sf::IntRect> frames_flip_;
  std::vector<sf::Texture> textures_;

  double current_frame_;
  double play_speed_;

  bool flip_;
  bool is_playing_;

  int32_t scale_;

  sf::Sprite sprite_;
};