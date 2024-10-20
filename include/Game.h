//
// Created by tsuna on 24/09/24.
//

#ifndef GAME_H
#define GAME_H

#include "Grid.h"
#include "Settings.h"

namespace model {
    class Game {

        int _score;
        int _max_score;
        Settings _settings;
        Grid _grid;
        void calculateMaxScore();
    public:
        Game();
        explicit Game(const Settings & settings);
        void play(const int & x, const int & y);
        Color getColor(const int & x, const int & y) const;

    };
}
#endif //GAME_H
