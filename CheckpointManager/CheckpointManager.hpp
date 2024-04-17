#ifndef CHECKPOINT_MANAGER
#define CHECKPOINT_MANAGER

#include "../Map/Map.hpp"
#include "../Player/Player.hpp"
#include "../DefaultSettings/DefaultSettings.hpp"

#include <iostream>
#include <fstream>
#include <filesystem>

struct State {
    double x_coord;
    double y_coord;
};


class CheckpointManager {
    public:
    CheckpointManager();

    CheckpointManager(State last_state): last_state_(last_state) {}

    void CheckCollision(Player& player, const MapParams& params);

    void SaveState(const State& state);

    void LoadState();

    void SetLastState(const State& state);

    State GetLastState();

    double GetX();

    double GetY();

    private:
    State last_state_;
    bool file_exists(const std::string& str) {
        std::ifstream fs(str);
        return fs.is_open();
    }

};

#endif