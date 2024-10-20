//
// Created by tsuna on 24/09/24.
//

#ifndef GAME_H
#define GAME_H

#include <set>

#include "Grid.h"
#include "Observable.h"
#include "Settings.h"

namespace model {
    class Game : public utils::Observable {

        int _score;
        int _max_score;
        Settings _settings;
        Grid _grid;
        std::set<utils::Observer*> _observers;
        void calculateMaxScore();
    public:
        Game();
        explicit Game(const Settings & settings);
        void play(const int & x, const int & y);
        Color getColor(const int & x, const int & y) const;
        int getRows() const;
        int getCols() const;

        void addObserver(utils::Observer *obs) override;
        void removeObserver(utils::Observer *obs) override;
        void notifyObserver() override;
    };
}
#endif //GAME_H
