#include "AnimationLoader.hpp"

struct AnimationParams;
AnimationLoader::AnimationLoader(const std::vector<AnimationParams>& animations)
    : animations_(animations) {}

void AnimationLoader::LoadSprites(AnimationManager& manager) {
  for (size_t i = 0; i < animations_.size(); ++i) {
    std::vector<sf::Texture> textures;
    size_t num = 0;

    while (
        file_exists(animations_[i].path + std::to_string(num + 1) + ".png")) {
      sf::Texture texture;
      texture.loadFromFile(animations_[i].path + std::to_string(num + 1) +
                           ".png");
      textures.push_back(texture);
      ++num;
    }

    manager.Create(animations_[i].name, textures, animations_[i].speed,
                   animations_[i].scale);
  }
}

AnimationLoader::AnimationLoader() = default;
