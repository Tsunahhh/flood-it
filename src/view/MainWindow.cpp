//
// Created by tsuna on 21/10/2024.
//
#include "MainWindow.h"
#include "SettingsView.h"

view::MainWindow::MainWindow(QWidget *parent) :
_game{nullptr},
_gameView{nullptr},
_settings{},
_horizontalLayout{nullptr},
_horizontalWidget{nullptr}

{
    setWindowTitle(tr("Flood It"));
    //setGeometry(QRect(0, 0, 1300, 690));

    _horizontalWidget = new QWidget(this);
    _horizontalLayout = new QHBoxLayout(_horizontalWidget);
    _horizontalWidget->setLayout(_horizontalLayout);

    this->setCentralWidget(_horizontalWidget);
    settingsView();
}

view::MainWindow::~MainWindow() {

}

void view::MainWindow::settingsView() {
    _settingsView = new SettingsView(this);
    _horizontalLayout->addWidget(_settingsView);
}

void view::MainWindow::playAGame() {

    if (_settingsView) {

        _settings = _settingsView->getSettings();

        int max = (_settings.width > _settings.height) ? _settings.width : _settings.height;
        this->setGeometry(QRect(0, 0, GAME_SIZE / max * _settings.width, GAME_SIZE / max * _settings.height));

        _game = new model::Game{_settings};
        _gameView = new GameView{_game, _horizontalWidget, _game->getRows(), _game->getCols()};
        _horizontalLayout->addWidget(_gameView);
        _game->addObserver(this);
    }
}

void view::MainWindow::gameOverView() {
    if (_gameView) {
        delete _gameView;
        _gameView = nullptr;
    }
    if (_game) {
        delete _game;
        _game = nullptr;
    }
}



void view::MainWindow::updateObs() {
    if (_game && _gameView) {
        _gameView->updateGameView();
        if (_game->isAllPlaced()) {
            exit(0);
        }
    }
}

