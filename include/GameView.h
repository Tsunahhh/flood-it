//
// Created by tsuna on 19/10/2024.
//

#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <mutex>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QBrush>
#include <QColor>
#include <QHeaderView>
#include <QMessageBox>

#include "Game.h"

namespace view {
    class GameView : public QTableWidget, public utils::Observer {
        Q_OBJECT
            int _WIDTH_WINDOW{1080};
            int _HEIGHT_WINDOW{1080};
            int _col;
            int _row;
            model::Game *_game;
        public:
            explicit GameView(model::Game *game, QWidget *parent = nullptr, const int & row=5, const int & col=5);
            QColor getQColor(const model::Color &color);
            void createColor(const int & x, const int & y, const QColor &color);
            void setColor(const int & x, const int & y, const QColor &color);
            void updateGameView();
            void updateObs() override;
            ~GameView() override;

        private slots:
            void onCellClicked(int row, int column);
    };
}


#endif //GAMEVIEW_H
