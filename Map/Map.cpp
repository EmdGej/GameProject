#include "Map.hpp"

int32_t Height = 45;
int32_t Width = 155;

std::vector<std::string> tilemap = {
    "B                                                                                                                                                         B",
    "B                                                                                                                                                         B",
    "B                                                                                                                                                         B",
    "B                                                                                                                                                         B",
    "B                                                                                                                                                         B",
    "B                                                                                                                                                         B",
    "B                                                                                                                                                         B",
    "B                                                                                                                                                         B",
    "B                                                                                                                                                         B",
    "B                                                                                                                                                         B",
    "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB    B",
    "BBBBBBBBBBBBBBBBBBBBB                                                                                                             B       B               B",
    "BB                  B                                                                                                             B       B               B",
    "BB                  B                                                                                                             B       B               B",
    "BB                  B                                                                                                             B       B               B",
    "BB                  B                                                                                                             B       B               B",
    "BB         C        B                                                                                                             B       B            FFFF",
    "BB        FFF       B                                                                                                             B       B               B",
    "BB                  B                                                                                                             B       B               B",
    "BB    FF       FF   B                                                                                                             B       B               B",
    "BB                  B                                                                                                             B       B               B",
    "BB                                                                            SSSSS                                               B       B               B",
    "BB                                                            FFFFFFFFFFFFFFFFFFFFF                                               B       B               B",
    "BB                                                            BBBBBBBBBBBBBBBBBBBBB                                               B       BBB             B",
    "BBFFFFFFFFFFFFFFFFFFFFFF                                   FFFBBBBBBBBBBBBBBBBBBBBB                                               B       B R             B",
    "B                                                             BBBBBBBBBBBBBBBBBBBBB                                               B       B               B",
    "B                                                             BBBBBBBBBBBBBBBBBBBBB                                              BB       B               B",
    "B                                                             BBBBBBBBBBBBBBBBBBBBB                                 S   C        R        BS              B",
    "B                                       SSS                   BBBBBBBBBBBBBBBBB                                   FFFFFFFFFB              BFF             B",
    "B                             FFFFF     BBB     FFF           BBBBBBBBBBBBBBBBB                                     BBBBBBBB              B               B",
    "B                             BBBBBSSSSSSSSSSSSSBR     FFFFFFFBBBBBBBBBBBBBBBBB                                     BBBBBBBB              B               B",
    "B                             BBBBBBBBBBBBBBBBBB       BBBBBBBBBBBBBBBBBBBBBBBB                                     BBBBBBBB              B               B",
    "B                                                      BBBBBBBBBBBBBBBBBBBBBBBB                                     BBBBBBBB              B               B",
    "B                                                      BBBBBBBBBBBBBBBBBBBBBBBB                                     BBBBBBBB      S       B               B",
    "B                                                      BBBBBBBBBBBBBBBBBBBBBBBB                                S    BBBBBBBB      FFFFFF  B          B    B",
    "B                                                      BBBBBBBBBBBBBBBBBBBBBBBB                                FFF  BBBBBBBB      B       B          R    B",
    "B                                                  S   BBBBBBBBBBBBBBBBBBBBBBBB                                     BBBBBBBB      B       B               B",
    "B                                            FFFFFFFFFFBBBBBBBBBBBBBBBBBBBBBBBB                                     BBBBBBBB      B       B               B",
    "B                                            BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB                                     BBBBBBBB      B  FFFFFB               B",
    "B                                            BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB                           S    S    BBBBBBBB      B       B             C B",
    "B                                            BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB                           FFFFFF    BBBBBBBB      B       B          SFFFFF",
    "B                                            BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB                           BBBBBB    BBBBBBBB      B                  B     ",
    "B                FFFFFFFFF     FFFF          BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB                           BBBBBB    BBBBBBBB      B                  B     ",
    "B    C        FFFBBBBBBBBBSSSSSBBBBSSSSSSSSSSBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBSSSSSSSSSFFSSSSSSSSSFSSSSSSBBBBBBSSSSBBBBBBBBSSSSSSB             C    B     ",
    "BFFFFFFFFFFFFFBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBFFFFFFFFFFFFFFFFFFF     ",
};

std::vector <AnimationParams> animations = {
            AnimationParams{"sprites/run/run", "run", 0.005, 2}, 
            AnimationParams{"sprites/stay/stay", "stay", 0.005, 2}, 
            AnimationParams{"sprites/jump/jump", "jump", 0.005, 2},
            AnimationParams{"sprites/stay_shoot/stay_shoot", "stay_shoot", 0.005, 2},
            AnimationParams{"sprites/run_shoot/run_shoot", "run_shoot", 0.005, 2},
            AnimationParams{"sprites/jump_shoot/jump_shoot", "jump_shoot", 0.005, 2},
            AnimationParams{"sprites/killed_lay/killed_lay", "killed_lay", 0.005, 2},
            AnimationParams{"sprites/bullet/bullet", "bullet", 0.005, 2},
            AnimationParams{"sprites/xeno-grunt-death-grounded/xeno-grunt-death-grounded", "xeno-grunt-death-grounded", 0.005, 3},
            AnimationParams{"sprites/xeno-grunt-death-falling/xeno-grunt-death-falling", "xeno-grunt-death-falling", 0.005, 3},
            AnimationParams{"sprites/xeno-grunt-run/xeno-grunt-run", "xeno-grunt-run", 0.005, 3}
};
