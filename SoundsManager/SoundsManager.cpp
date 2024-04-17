#include "SoundsManager.hpp"

void SoundsManager::LoadSounds(const std::vector<std::pair<std::string, std::string>>& sounds) {
  for (auto& sound: sounds) {
    sf::SoundBuffer* buffer = new sf::SoundBuffer;
    buffer->loadFromFile(sound.second);
    
    sf::Sound* snd = new sf::Sound(*buffer);

    sounds_[sound.first] = {buffer, snd};
  }
}

void SoundsManager::LoadMusics(const std::vector<std::pair<std::string, std::string>>& musics, const std::vector<bool>& repeat) {
  size_t i = 0;

  for (auto& music: musics) {
    sf::Music* msc = new sf::Music();
    msc->openFromFile(music.second);

    if (repeat[i]) {
      msc->setLoop(true);
    }

    musics_[music.first] = msc;

    ++i;
  }
}

void SoundsManager::PlaySound(const std::string& sound) {
  sounds_[sound].second->play();
}

void SoundsManager::PlayMusic(const std::string& music) {
  musics_[music]->play();
}

void SoundsManager::StopSound(const std::string& sound) {
  sounds_[sound].second->stop();
}

void SoundsManager::StopMusic(const std::string& music) {
  musics_[music]->stop();
}