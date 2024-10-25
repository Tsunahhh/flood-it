//
// Created by tsuna on 21/10/2024.
//

#include <QScreen>

#include "MainWindow.h"
#include "SettingsView.h"

view::MainWindow::MainWindow(QWidget *parent) :
_game{nullptr},
_gameView{nullptr},
_gameOverView{nullptr},
_settingsView{nullptr},
_settings{},
_horizontalLayout{nullptr},
_horizontalWidget{nullptr}

{
    setWindowTitle(tr("Flood It"));

    _horizontalWidget = new QWidget(this);
    _horizontalLayout = new QHBoxLayout(_horizontalWidget);
    _horizontalWidget->setLayout(_horizontalLayout);

    this->setCentralWidget(_horizontalWidget);
    connect(this, &MainWindow::signalGameOver, this, &MainWindow::gameOverView);

    settingsView();
}

view::MainWindow::~MainWindow() {

}

void view::MainWindow::settingsView() {
    if (_gameOverView != nullptr) {
        _horizontalLayout->removeWidget(_gameOverView);
        delete _gameOverView;
        _gameOverView = nullptr;
    }

    _settingsView = new SettingsView(this);
    connect(_settingsView, &SettingsView::play, this, &MainWindow::playAGame);
    connect(_settingsView, &SettingsView::leave, this, &MainWindow::leave);
    _horizontalLayout->addWidget(_settingsView);
    setGeometry(QRect(500, 300, 0, 0));
}

void view::MainWindow::playAGame() {
    if (_settingsView) {
        _settings = _settingsView->getSettings();
        _horizontalLayout->removeWidget(_settingsView);
        delete _settingsView;
        _settingsView = nullptr;
    }

    if (_gameOverView) {
        _horizontalLayout->removeWidget(_gameOverView);
        delete _gameOverView;
        _gameOverView = nullptr;
    }

    int max = (_settings.width > _settings.height) ? _settings.width : _settings.height;

    this->resize( GAME_SIZE / max * _settings.width, GAME_SIZE / max * _settings.height);

    _game = new model::Game{_settings};
    _gameView = new GameView{_game, _horizontalWidget, _game->getRows(), _game->getCols()};
    _horizontalLayout->addWidget(_gameView);
    _game->addObserver(this);
}

void view::MainWindow::gameOverView() {
    model::Settings playerResult;
    if (_gameView != nullptr) {
        _horizontalLayout->removeWidget(_gameView);
        delete _gameView;
        _gameView = nullptr;
    }
    if (_game != nullptr) {
        playerResult = _game->getPlayerStates();
        _game->removeObserver(this);
        delete _game;
        _game = nullptr;
    }
    _gameOverView = new GameOverView(playerResult, this);
    _horizontalLayout->addWidget(_gameOverView);
    connect(_gameOverView, &GameOverView::replay, this, &MainWindow::playAGame);
    connect(_gameOverView, &GameOverView::settings, this, &MainWindow::settingsView);
    connect(_gameOverView, &GameOverView::leave, this, &MainWindow::leave);
    setGeometry(QRect(500, 300, 0, 0));
}

void view::MainWindow::updateObs() {
    if (_game && _gameView) {
        _gameView->updateGameView();

        if (_game->isAllPlaced()) {
            emit signalGameOver();
        }
    }
}

void view::MainWindow::leave() {
    exit(0);
}



