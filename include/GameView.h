//
// Created by tsuna on 21/10/2024.
//

#ifndef FLOOD_IT_GAMEVIEW_H
#define FLOOD_IT_GAMEVIEW_H

#include <QGridLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QColor>
#include <vector>

#include "Game.h"
#include "CaseView.h"



namespace view {
    class GameView : public QWidget {
        Q_OBJECT

        static const int SIZE_WIN{500};

        int _col;
        int _row;

        model::Game *_game;
        QGridLayout *_gridLayout;

        std::vector<std::vector<CaseView* >> _casesRegister;
    public:
        explicit GameView(model::Game *game, QWidget *parent = nullptr, const int & row=5, const int & col=5);
        QColor getQColor(const model::Color &color);
        void setColor(const int & x, const int & y, const QColor &color);
        void updateGameView();
        ~GameView() override;

    private slots:
        void onCellClicked(int x, int y);
    };
}

#endif //FLOOD_IT_GAMEVIEW_H
