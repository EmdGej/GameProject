#ifndef ANIMATION_LOADER
#define ANIMATION_LOADER

/*
AnimationLoader - класс, который позволяет загрузить спрайты по их параметрам.

Констрируется от массива AnimationParams. В AnimationParams содержится название
path - путь до папки с нужными текстурами, name - название спрайта.

LoadSprites - метод принимающий AnimationManager и загружающий в него
соответствующие спрайты.
*/

#include <fstream>
#include <iostream>

#include "../AnimationManager/AnimationManager.hpp"

struct AnimationParams {
  std::string path;
  std::string name;
  double speed;
  int scale;
};
class AnimationLoader {
 public:
  AnimationLoader(const std::vector<AnimationParams>& animations);
  void LoadSprites(AnimationManager& manager);

 private:
  bool file_exists(const std::string& str) {
    std::ifstream fs(str);
    return fs.is_open();
  }
  std::vector<AnimationParams> animations_;
};

#endif
