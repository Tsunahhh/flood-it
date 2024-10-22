#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <QLabel>

#include "Grid.h"
#include "GameView.h"
#include "GameView2.h"
#include "Game.h"
#include "MainWindow.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);


    view::MainWindow mainWin;
    mainWin.show();
    return QApplication::exec();
}
