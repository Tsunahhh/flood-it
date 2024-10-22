//
// Created by tsuna on 21/10/2024.
//

#ifndef FLOOD_IT_MAINWINDOW_H
#define FLOOD_IT_MAINWINDOW_H

#include <QMainWindow>

#include "Game.h"
#include "GameView2.h"

namespace view {
    class MainWindow : public QMainWindow {
        Q_OBJECT

        QVBoxLayout * _verticalLayout;
        QWidget * _verticalWidget;
        QHBoxLayout * _horizontalLayout;
        QWidget * _horizontalWidget;

        model::Game* _game;
        model::Settings _settings;
    public:
        explicit MainWindow(QWidget *parent = nullptr);
        void playAGame();
        void settingsView();
        void gameOverView();
        ~MainWindow();
    };
}


#endif //FLOOD_IT_MAINWINDOW_H
