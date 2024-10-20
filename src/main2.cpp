//
// Created by tsuna on 20/10/2024.
//

#include <iostream>
#include "../include/Settings.h"
#include "../include/Game.h"


int main(int argc, char *argv[]) {

    //QApplication app(argc, argv);


    const model::Settings settings = {10, 10, 4};

    std::cout << "au game" << std::endl;
    model::Game game{settings};
    std::cout << "fin game " << std::endl;

    //view::GameView view{ &game, nullptr, 10, 10};
    //view.show();
    exit(5); //QApplication::exec();
}