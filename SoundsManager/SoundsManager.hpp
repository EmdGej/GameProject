#ifndef SOUNDS_MANAGER
#define SOUNDS_MANAGER

#include <SFML/Audio.hpp>

#include <unordered_map>
#include <vector>

class SoundsManager {
 public:
  void LoadSounds(const std::vector<std::pair<std::string, std::string>>& sounds);

  void LoadMusics(const std::vector<std::pair<std::string, std::string>>& musics, const std::vector<bool>& repeat);

  void PlaySound(const std::string& sound);

  void PlayMusic(const std::string& music);

  void StopSound(const std::string& sound);

  void StopMusic(const std::string& music);

  ~SoundsManager();
  
 private:
  std::unordered_map<std::string, std::pair<sf::SoundBuffer*, sf::Sound*>> sounds_;
  std::unordered_map<std::string, sf::Music*> musics_;
};

#endif