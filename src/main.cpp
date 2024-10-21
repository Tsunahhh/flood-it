#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <QLabel>

#include "Grid.h"
#include "GameView.h"
#include "GameView2.h"
#include "Game.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);


    const model::Settings settings = {10, 10, 10}; // limite 80x80

    model::Game game{settings};

    view::GameView2 view{ &game, nullptr, game.getRows(), game.getCols()};

    game.addObserver(&view);

    view.show();
    return QApplication::exec();
}
