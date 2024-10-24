#include <iostream>
#include <ostream>

#include "Grid.h"
#include "Settings.h"
#include "Game.h"

model::Game::Game(const Settings & settings):
        _grid{settings.height,settings.width, settings.colors},
        _settings(model::Settings())
{
}


void model::Game::play(const int &x, const int &y) {
    const Color selectedColor { _grid.getColor(x, y) };
    _grid.playColor(selectedColor);
    _settings.score++;
    notifyObserver();
}

model::Color model::Game::getColor(const int & x, const int & y) const {
    return _grid.getColor(x, y);
}

int model::Game::getRows() const {
    return _grid.getRows();
}

int model::Game::getCols() const {
    return _grid.getCols();
}

int model::Game::getScore() const {
    return _settings.score;
}

bool model::Game::isAllPlaced() const {
    return _grid.isAllSame();
}

void model::Game::addObserver(utils::Observer *obs) {
    _observers.insert(obs);
}

void model::Game::removeObserver(utils::Observer *obs) {
    _observers.erase(obs);
}

void model::Game::notifyObserver() {
    for (utils::Observer *obs : _observers) {
        obs->updateObs();
    }
}



