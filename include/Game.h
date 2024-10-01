//
// Created by tsuna on 24/09/24.
//

#ifndef GAME_H
#define GAME_H

#include "Grid.h"
#include "Settings.h"

namespace model {
    class Game {
    private:
        int _score;
        Settings _settings;
        Grid _grid;
    public:
        explicit Game(Settings settings);
    };
}
#endif //GAME_H
