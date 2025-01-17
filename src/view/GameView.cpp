//
// Created by tsuna on 21/10/2024.
//
#include <iostream>
#include "GameView.h"

view::GameView::GameView(model::Game *game, QWidget *parent, const int &row, const int &col) :
    _game(game), QWidget(parent), _row(row), _col(col)
{
    _gridLayout = new QGridLayout(this);
    _gridLayout->setContentsMargins(0, 0, 0, 0);
    _gridLayout->setSpacing(0);

    _casesRegister.resize(row);
    for (int i = 0; i < row; ++i) {
        _casesRegister[i].resize(col);
    }

    for (int i = 0; i < _row; ++i) {
        for (int j = 0; j < _col; ++j) {
            CaseView* caseView = new CaseView(j, i, getQColor(_game->getColor(j, i)), this);
            _casesRegister[i][j] = caseView;
            connect(caseView, &CaseView::clicked, this, &GameView::onCellClicked);
            _gridLayout->addWidget(caseView, i, j);
        }
    }
    setLayout(_gridLayout);
}

QColor view::GameView::getQColor(const model::Color &color) const {
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

void view::GameView::setColor(const int &x, const int &y, const QColor &color) {
    _casesRegister.at(y).at(x)->setColor(color);
}

void view::GameView::updateGameView() {
    for (int i = 0; i < _row; i++) {
        for (int j =0; j < _col; j++) {
            setColor(j, i, getQColor(_game->getColor(j, i)));
        }
    }
}

view::GameView::~GameView() {

};

void view::GameView::onCellClicked(const int &row, const int &col) {
    _game->play(col, row);
}

