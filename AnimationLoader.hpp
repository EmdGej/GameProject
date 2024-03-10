#include "AnimationManager.hpp"
#include <fstream>
class AnimationLoader {
    public:
    AnimationLoader(const std::vector<std::pair<std::string, std::string>>& sprites_dir): sprites_dir_(sprites_dir) {}
    void LoadSprites(AnimationManager& manager) {
        for(size_t i = 0; i < sprites_dir_.size(); ++i) {
            std::vector<sf::Texture> textures;
            std::fstream fileStream;
            size_t num = 0;
            fileStream.open(sprites_dir_[i].first + std::to_string(num + 1) + ".png");
            while(!fileStream.fail()) {
                sf::Texture texture;
                texture.loadFromFile(sprites_dir_[i].first + std::to_string(i) + ".png");
                textures.push_back(texture);
                ++num;
                fileStream.open(sprites_dir_[i].first + std::to_string(num + 1) + ".png");
            }
            manager.Create(sprites_dir_[i].second, textures,0.005, 8);
        }
    }
    private:
    std::vector<std::pair<std::string, std::string>> sprites_dir_;
    
};
