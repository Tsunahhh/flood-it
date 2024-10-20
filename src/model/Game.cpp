#include <iostream>
#include <ostream>

#include "Grid.h"
#include "Settings.h"
#include "Game.h"

model::Game::Game() :
    _grid{10, 10, 4},
    _score(0),
    _max_score(25),
    _settings(model::Settings())
{
    std::cout << "Game constructor default" << std::endl;
}

model::Game::Game(const Settings & settings):
        _grid{settings.height,settings.width, settings.colors},
        _score(0),
        _max_score(25),
        _settings(model::Settings())
{
    std::cout << "Game initialized" << std::endl;
}


void model::Game::play(const int &x, const int &y) {
    const Color selectedColor { _grid.getColor(x, y) };
    _grid.playColor(selectedColor);
}

model::Color model::Game::getColor(const int & x, const int & y) const {
    return _grid.getColor(x, y);
}

void model::Game::calculateMaxScore() {
    _max_score = 25;
}



