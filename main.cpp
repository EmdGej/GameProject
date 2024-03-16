#include "Game/Game.hpp"

int main() {
    Game game_manager(1920, 1080);

    game_manager.GameLoop();

    return 0;
}   