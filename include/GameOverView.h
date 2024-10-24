//
// Created by tsuna on 22/10/24.
//

#ifndef GAMEOVERVIEW_H
#define GAMEOVERVIEW_H

#include <QWidget>

#include "SettingsView.h"

namespace view {
    class GameOverView : QWidget {
        Q_OBJECT

        std::vector<model::Settings> states;


            //void loadLeaderBoard();
            //void createLeaderBoard();
            //void saveLeaderBoard();


        public:
            explicit GameOverView(QWidget *parent = nullptr);
            void showLeaderBoard();

        signals:
    };
}

#endif //GAMEOVERVIEW_H
