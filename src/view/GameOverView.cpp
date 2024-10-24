//
// Created by tsuna on 22/10/2024.
//
#include "GameOverView.h"


view::GameOverView::GameOverView(model::Settings settings, QWidget *parent) :

QWidget(parent),
_layout{new QVBoxLayout(this)}
{
    initLBL();
    initBTN();
}

void view::GameOverView::initLBL() {
    _gameOverLBL = new QLabel("Partie terminée !", this);
    _gameOverLBL->setAlignment(Qt::AlignCenter);
    _layout->addWidget(_gameOverLBL);

    std::string scoreStr = "Score: ";
    _scoreLBL = new QLabel("Votre score est " , this);
    _scoreLBL->setAlignment(Qt::AlignCenter);
    _layout->addWidget(_scoreLBL);

    _recordLBL = new QLabel("Le record est de {} et détenu par {}", this);
    _recordLBL->setAlignment(Qt::AlignCenter);
    _layout->addWidget(_recordLBL);
}

void view::GameOverView::initBTN() {
    _buttonLayout = new QHBoxLayout(this);

    _buttonLayout->setSpacing(5);
    _buttonLayout->setAlignment(Qt::AlignCenter);

    _buttonLayout->addWidget(_replayBT);
    _buttonLayout->addWidget(_settingBT);
    _buttonLayout->addWidget(_leaveBT);

    connect(_replayBT, &QPushButton::clicked, this, &GameOverView::replay);
    connect(_replayBT, &QPushButton::clicked, this, &GameOverView::settings);
    connect(_replayBT, &QPushButton::clicked, this, &GameOverView::leave);

    _layout->addLayout(_buttonLayout);
}



