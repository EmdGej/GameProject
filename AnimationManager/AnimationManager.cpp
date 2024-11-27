#include "AnimationManager.hpp"

void AnimationManager::Create(std::string animation_name,
                              const std::vector<sf::Texture>& textures,
                              double play_speed, int32_t scale) {
  animations_list_[animation_name] = Animation(textures, play_speed, scale);
  current_animation_ = animation_name;
}

void AnimationManager::Draw(sf::RenderWindow& window, int32_t x, int32_t y) {
  animations_list_[current_animation_].SetSpritePosition(x, y);
  animations_list_[current_animation_].DrawSpriteOnWindow(window);
}

void AnimationManager::SetAnimation(std::string animation_name) {
  current_animation_ = animation_name;
}

void AnimationManager::SetFlip(bool flip) {
  animations_list_[current_animation_].SetFlip(flip);
}

void AnimationManager::UpdateFrame(double time) {
  animations_list_[current_animation_].UpdateFrame(time);
}

void AnimationManager::SetAnimationPause() {
  animations_list_[current_animation_].SetIsPlaying(false);
}

void AnimationManager::SetAnimationPlay() {
  animations_list_[current_animation_].SetIsPlaying(true);
}

int32_t AnimationManager::GetAnimationHeight() {
  return animations_list_[current_animation_].GetAnimationHeight();
}

int32_t AnimationManager::GetAnimationWidth() {
  return animations_list_[current_animation_].GetAnimationWidth();
}