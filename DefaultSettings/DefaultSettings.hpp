#ifndef DEFAULT_SETTINGS
#define DEFAULT_SETTINGS

#include <stdint.h>

namespace DefaultSettings {
    namespace PlayerSettings {
        const int32_t x_coord = 300;
        const int32_t y_Coord = 700;
        const int32_t health = 100;
        const int32_t damage = 1;
        const double acceleration = 0.0015;
        const double stamina = 100;
    }

    namespace EnemySettings {
        const double x_speed = 0.1;
    }
}

#endif