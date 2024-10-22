//
// Created by tsuna on 21/10/2024.
//
#include "MainWindow.h"

view::MainWindow::MainWindow(QWidget *parent) :
_game(nullptr),
_horizontalLayout(nullptr),
_horizontalWidget(nullptr),
_verticalLayout(nullptr),
_verticalWidget(nullptr)
{

}

view::MainWindow::~MainWindow() {

}

void view::MainWindow::playAGame() {
    const model::Settings settings = {26, 26, 10}; // limite 80x80
    model::Game game{settings};
    view::GameView2 view{ &game, nullptr, game.getRows(), game.getCols()};
    game.addObserver(&view);
}

void view::MainWindow::gameOverView() {

}

void view::MainWindow::settingsView() {

}

