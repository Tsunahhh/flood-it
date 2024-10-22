//
// Created by tsuna on 21/10/2024.
//
#include "MainWindow.h"

view::MainWindow::MainWindow(QWidget *parent):
_game{nullptr},
_settings{},
_verticalLayout{nullptr},
_verticalWidget{nullptr}

{
    setWindowTitle(tr("Flood It"));
    setGeometry(QRect(0, 0, 1300, 690));
    _verticalWidget = new QWidget(this);
    _verticalLayout = new QVBoxLayout(_verticalWidget);
    _verticalWidget->setLayout(_verticalLayout);
    this->setCentralWidget(_verticalWidget);
    playAGame();
}

view::MainWindow::~MainWindow() {

}

void view::MainWindow::playAGame() {
    _settings = {15, 10, 10};
    _game = new model::Game{_settings};
    _gameView = new GameView2{ _game, _verticalWidget, _game->getRows(), _game->getCols()};
    _verticalLayout->addWidget(_gameView);
    _game->addObserver(this);
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

void view::MainWindow::settingsView() {

}

void view::MainWindow::updateObs() {
    if (_game && _gameView) {
        _gameView->updateGameView();
        if (_game->isAllPlaced()) {
            exit(0);
        }
    }
}

