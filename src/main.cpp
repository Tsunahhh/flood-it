#include <QApplication>
#include <QPushButton>
#include <QLabel>

#include "Grid.h"
#include "GameView.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    model::Grid grid {20, 20, 7};
    view::GameView view{nullptr, 10, 10};
    view.show();
    return QApplication::exec();
}
