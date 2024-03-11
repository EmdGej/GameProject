#include "Animation.hpp"

Animation::Animation() = default;

Animation::Animation(const std::vector<sf::Texture>& textures,
                     double play_speed, int32_t scale)
    : textures_(textures), play_speed_(play_speed), scale_(scale) {
  frames_.resize(textures_.size());
  frames_flip_.resize(textures_.size());

  for (size_t i = 0; i < textures_.size(); ++i) {
    frames_[i] =
        sf::IntRect(0, 0, textures_[i].getSize().x, textures_[i].getSize().y);
    frames_flip_[i] =
        sf::IntRect(textures_[i].getSize().x, 0, -textures_[i].getSize().x,
                    textures_[i].getSize().y);
  }

  current_frame_ = 0;
  flip_ = false;
  is_playing_ = true;
}

void Animation::UpdateFrame(double time) {
  if (!is_playing_) {
    return;
  }

  current_frame_ += play_speed_ * time;

  if (current_frame_ >= frames_.size()) {
    current_frame_ -= frames_.size();
  }

  sprite_.setTexture(textures_[static_cast<int32_t>(current_frame_)], true);
  sprite_.setScale(scale_, scale_);
  if (flip_) {
    sprite_.setTextureRect(frames_flip_[static_cast<int32_t>(current_frame_)]);
  } else {
    sprite_.setTextureRect(frames_[static_cast<int32_t>(current_frame_)]);
  }
}

void Animation::SetSpritePosition(int32_t x, int32_t y) {
  sprite_.setPosition(x, y);
}

void Animation::DrawSpriteOnWindow(sf::RenderWindow& window) {
  window.draw(sprite_);
}

// =========== GETTERS ============ //

double Animation::GetCurrentFrame() const { return current_frame_; }

double Animation::GetPlaySpeed() const { return play_speed_; }

bool Animation::GetFlip() const { return flip_; }

bool Animation::GetIsPlaying() const { return is_playing_; }

int32_t Animation::GetScale() const { return scale_; }

// =========== SETTERS ============ //

void Animation::SetCurrentFrame(double current_frame) {
  current_frame_ = current_frame;
}

void Animation::SetPlaySpeed(double play_speed) { play_speed_ = play_speed; }

void Animation::SetFlip(bool flip) { flip_ = flip; }

void Animation::SetIsPlaying(bool is_playing) { is_playing_ = is_playing; }

void Animation::SetScale(int32_t scale) { scale_ = scale; }

int32_t Animation::GetAnimationWidth() { return frames_[0].width; }
int32_t Animation::GetAnimationHeight() { return frames_[0].height; }