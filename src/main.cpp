#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <QLabel>

#include "Grid.h"
#include "GameView.h"
#include "Game.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);


    const model::Settings settings = {5, 5, 10};

    model::Game game{settings};

    view::GameView view{ &game, nullptr, game.getRows(), game.getCols()};

    game.addObserver(&view);

    view.show();
    return QApplication::exec();
}
