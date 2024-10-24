//
// Created by tsuna on 22/10/24.
//

#ifndef GAMEOVERVIEW_H
#define GAMEOVERVIEW_H

#include <QWidget>
#include <fstream>
#include <vector>
#include <iostream>
#include <string>

#include "SettingsView.h"

// Your score is {}, the best score is {}

// Remplacer l'ancien score par le nouveau si meilleur pour une config
// Replay with same config
// Settings
// Leave

namespace view {
    class GameOverView : public QWidget {
        Q_OBJECT
            std::string FILE_PATH = "saves.bin";

            std::vector<model::Settings> _states;
            QVBoxLayout *_layout;
            QHBoxLayout *_buttonLayout;

            QLabel *_gameOverLBL;
            QLabel *_scoreLBL;
            QLabel *_recordLBL;

            QPushButton *_replayBT;
            QPushButton *_settingBT;
            QPushButton *_leaveBT;

            model::Settings _settings;
            model::Settings getBestScore();
            void loadSettingsRecords(const std::string& filename);
            void saveSettingsRecords(const std::string& filename);
            model::Settings loadSettings(std::ifstream & inFile);
            void saveSettings(std::ofstream &outFile);

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
