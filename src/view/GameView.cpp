//
// Created by tsuna on 24/09/24.
//
#include "GameView.h"

#include <iostream>

view::GameView::GameView(model::Game* game, QWidget *parent, const int & row, const int & col) : QTableWidget(parent), _col(col), _row(row), _game(game){

    setRowCount(_row);
    setColumnCount(_col);

    setGeometry(QRect(0, 0, _WIDTH_WINDOW, _HEIGHT_WINDOW));
    setEditTriggers(QAbstractItemView::NoEditTriggers);
    setSelectionMode(QAbstractItemView::NoSelection);
    horizontalHeader()->setVisible(false);
    verticalHeader()->setVisible(false);

    for (int i = 0; i < _row; i++) {
        setRowHeight(i, _HEIGHT_WINDOW / _row);
    }

    for (int i = 0; i < _col; i++) {
        setColumnWidth(i, _WIDTH_WINDOW / _col);
    }

    updateGameView();

    std::cout << "map loaded" << std::endl;

    connect(this, &QTableWidget::cellClicked, this, GameView::onCellClicked);
    setStyleSheet("QTableWidget { border: none; } QTableWidget::item { padding: 0; margin: 0;}");
}

void view::GameView::onCellClicked(int row, int col) {
    //this->_game->play(col, row);
}

QColor view::GameView::getQColor(const model::Color & color) {
    QColor result;
    switch (color.getIdValue()) {
        case model::Color::RED:
            result = {255, 0, 0};
            break;
        case model::Color::GREEN:
            result =  {0, 255, 0};
            break;
        case model::Color::BLUE:
            result = {0, 0, 255};
            break;
        case model::Color::WHITE:
            result = {255, 255, 255};
            break;
        case model::Color::BLACK:
            result = {0, 0, 0};
            break;
        case model::Color::YELLOW:
            result = {255, 232, 23};
            break;
        case model::Color::CYAN:
            result = {33, 243, 255};
            break;
        case model::Color::ORANGE:
            result = {255, 138, 51};
            break;
        case model::Color::PURPLE:
            result = {159, 51, 255};
            break;
        case model::Color::ROSE:
            result = {255, 51, 240};
            break;
        default:
            result = {0, 0, 0};
    }

    return result;
}

void view::GameView::setColor(const int & x, const int & y, const QColor & color) {
    if (y >= 0 && x >= 0 && y < _row && x < _col) {
            auto *item = new QTableWidgetItem();
            item->setBackground(QBrush(color));
            setItem(y, x, item);
    }
}

void view::GameView::updateGameView() {
    for (int i = 0; i < _row; i++) {
        for (int j = 0; j < _col; j++) {
            setColor(j, i, getQColor(_game->getColor(i, j)));
        }
    }
}

view::GameView::~GameView() {
    //delete _game;
    //_game = nullptr;
}

