#include "AnimationLoader.hpp"

int main() {
    std::vector<std::pair<std::string, std::string>> v = {{"sprites/climb/climb", "climb"}, {"sprites/run/run", "run"}};
    AnimationManager manager;
    AnimationLoader loader(v);
    loader.LoadSprites(manager);
}