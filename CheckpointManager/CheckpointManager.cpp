#include "CheckpointManager.hpp"

CheckpointManager::CheckpointManager() {
    if(!file_exists("saves/save.txt")) {
        std::filesystem::create_directory("saves");
        std::ofstream file("saves/save.txt");
        SaveState({DefaultSettings::PlayerSettings::x_coord, DefaultSettings::PlayerSettings::y_coord});
    }
}

void CheckpointManager::CheckCollision(Player& player, const MapParams& params) {
for (int32_t i = player.GetYCoord() / params.tile_size;
        i < (player.GetYCoord() + player.GetAnimationHeight()) / params.tile_size;
        ++i) {
    for (int32_t j = player.GetXCoord() / params.tile_size;
        j < (player.GetXCoord() + player.GetAnimationWidth()) / params.tile_size;
        ++j) {
        if(params.map[i][j] == 'C') {
            last_state_ = {player.GetXCoord(), player.GetYCoord()};
            SaveState(last_state_);
        }
        }
    }
}

void CheckpointManager::SaveState(const State& state) {
    std::ofstream out;
    out.open("saves/save.txt");
    if(out.is_open()) {
        out << state.x_coord << '\n' << state.y_coord;
    }
    out.close();
}

void CheckpointManager::LoadState() {
    std::ifstream in("saves/save.txt");
    if(in.is_open()) {
        in >> last_state_.x_coord >> last_state_.y_coord;
    }
    in.close();
}

void CheckpointManager::SetLastState(const State& state) {
    last_state_ = state;
}

State CheckpointManager::GetLastState() {
    return last_state_;
}

double CheckpointManager::GetX() {
    return last_state_.x_coord;
}

double CheckpointManager::GetY() {
    return last_state_.y_coord;
}