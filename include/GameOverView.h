//
// Created by tsuna on 22/10/24.
//

#ifndef GAMEOVERVIEW_H
#define GAMEOVERVIEW_H

#include <QWidget>

#include "SettingsView.h"

// Your score is {}, the best score is {}

// Remplacer l'ancien score par le nouveau si meilleur pour une config
// Replay with same config
// Settings
// Leave

namespace view {
    class GameOverView : QWidget {
        Q_OBJECT
            std::vector<model::Settings> states;

            QVBoxLayout *_layout;

            QHBoxLayout *_buttonLayout;

            QLabel *_gameOverLBL; // Partie est finie !
            QLabel *_scoreLBL;  // Votre score est : {SCORE}
            QLabel *_recordLBL; // le record est {BESTSCORE} de {NAME}

            QPushButton *_replayBT;
            QPushButton *_settingBT;
            QPushButton *_leaveBT;

            void getBestScore(const int & height, const int & width, const int & colors);
            void loadScoresRecords(); // Récupérer les scores d'un fichier
            void saveScoreRecords();  // Enregistrer les scores dans un fichier

        public:
            explicit GameOverView(model::Settings settings, QWidget *parent = nullptr);
            void initLBL();
            void initBTN();

        signals:
            void replay();
            void settings();
            void leave();
    };
}

#endif //GAMEOVERVIEW_H
