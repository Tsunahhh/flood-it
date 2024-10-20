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

}

model::Game::Game(const Settings & settings):
        _grid{settings.height,settings.width, settings.colors},
        _score(0),
        _max_score(25),
        _settings(model::Settings())
{
}


void model::Game::play(const int &x, const int &y) {
    const Color selectedColor { _grid.getColor(x, y) };
    _grid.playColor(selectedColor);
    notifyObserver();
}

model::Color model::Game::getColor(const int & x, const int & y) const {
    return _grid.getColor(x, y);
}

void model::Game::calculateMaxScore() {
    _max_score = 25;
}

int model::Game::getRows() const {
    return _grid.getRows();
}

int model::Game::getCols() const {
    return _grid.getCols();
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





