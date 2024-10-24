//
// Created by tsuna on 21/10/2024.
//

#ifndef FLOOD_IT_MAINWINDOW_H
#define FLOOD_IT_MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QStackedLayout>

#include "Game.h"
#include "GameView.h"
#include "SettingsView.h"
#include "GameOverView.h"

namespace view {
    class MainWindow : public QMainWindow, public utils::Observer {
        Q_OBJECT

        static const int GAME_SIZE { 500 };

        QHBoxLayout *_horizontalLayout;
        QWidget *_horizontalWidget;

        SettingsView *_settingsView;
        GameView *_gameView;
        GameOverView *_gameOverView;

        model::Game* _game;
        model::Settings _settings;
    public:
        explicit MainWindow(QWidget *parent = nullptr);
        void updateObs() override;
        ~MainWindow();
    signals:
        void signalGameOver();
    public slots:
        void leave();
        void playAGame();
        void settingsView();
        void gameOverView();
    };
}


#endif //FLOOD_IT_MAINWINDOW_H