#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <QLabel>

#include "Grid.h"
#include "GameView.h"
#include "Game.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);


    const model::Settings settings = {10, 10, 4};

    model::Game game{settings};

    view::GameView view{ &game, nullptr, 10, 10};
    view.show();
    return QApplication::exec();
}
