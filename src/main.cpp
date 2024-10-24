#include <QApplication>

#include "MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    view::MainWindow mainWin;
    mainWin.show();
    return QApplication::exec();
}
