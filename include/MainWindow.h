//
// Created by tsuna on 21/10/2024.
//

#ifndef FLOOD_IT_MAINWINDOW_H
#define FLOOD_IT_MAINWINDOW_H

#include <QMainWindow>

#include "Game.h"
#include "GameView2.h"

namespace view {
    class MainWindow : public QMainWindow, public utils::Observer {
        Q_OBJECT

        QVBoxLayout * _verticalLayout;
        QWidget * _verticalWidget;

        GameView2 * _gameView;

        model::Game* _game;
        model::Settings _settings;
    public:
        explicit MainWindow(QWidget *parent = nullptr);
        void playAGame();
        void settingsView();
        void gameOverView();
        void updateObs() override;
        ~MainWindow();
    };
}


#endif //FLOOD_IT_MAINWINDOW_H
