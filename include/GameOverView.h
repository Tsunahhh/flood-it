#ifndef GAMEOVERVIEW_H
#define GAMEOVERVIEW_H

#include <QWidget>
#include <fstream>
#include <vector>
#include <iostream>
#include <string>

#include "SettingsView.h"

/**
 * @file GameOverView.h
 * @brief Declares the GameOverView class for managing the game's end screen.
 *
 * The GameOverView class provides a UI that displays the player's score,
 * the best score, and allows the user to replay, access settings, or leave.
 */

namespace view {

    /**
     * @class GameOverView
     * @brief Represents the game over screen, showing the player's score, the best score,
     * and providing options for replaying, modifying settings, or exiting the game.
     */
    class GameOverView : public QWidget {
    Q_OBJECT

        static constexpr  std::string FILE_PATH = "saves.bin"; ///< File path for saving/loading game records.

        std::vector<model::Settings> _states; ///< Stores game state records from past plays.
        QVBoxLayout *_layout; ///< Vertical layout for arranging labels and buttons.
        QWidget *_buttonWidget{}; ///< Widget for arranging buttons
        QHBoxLayout *_buttonLayout{}; ///< Horizontal layout for arranging buttons.

        QLabel *_gameOverLBL{}; ///< Label to display the "Game Over" message.
        QLabel *_scoreLBL{}; ///< Label to display the player's score.
        QLabel *_recordLBL{}; ///< Label to display the best score record.

        QPushButton *_replayBT{}; ///< Button to allow the player to replay with the same settings.
        QPushButton *_settingBT{}; ///< Button to access the settings menu.
        QPushButton *_leaveBT{}; ///< Button to leave the game.

        const model::Settings _settings; ///< The current game settings, including the player's score.

        /**
         * @brief Retrieves the best score from the recorded states that match the current game's settings.
         *
         * @return The highest score for the current configuration.
         */
        int getBestScore();

        /**
         * @brief Loads game settings records from a file.
         *
         * @param filename The file path from which the settings are loaded.
         */
        void loadSettingsRecords(const std::string& filename);

        /**
         * @brief Saves the current game settings records to a file.
         *
         * @param filename The file path where the settings are saved.
         */
        void saveSettingsRecords(const std::string& filename);

        /**
         * @brief Loads an individual game setting from a file stream.
         *
         * @param inFile The input file stream to read from.
         * @return The loaded settings.
         */
        model::Settings loadSettings(std::ifstream & inFile);

        /**
         * @brief Saves the current game settings to a file stream.
         *
         * @param outFile The output file stream to write to.
         */
        void saveSettings(std::ofstream &outFile, const model::Settings &settings);

    public:
        /**
         * @brief Constructs the GameOverView, initializing UI components and handling game state records.
         *
         * @param settings The settings of the game just completed, including the player's score.
         * @param parent The parent widget, if any (optional).
         */
        explicit GameOverView(model::Settings settings, QWidget *parent = nullptr);

        /**
         * @brief Initializes the labels displayed on the game over screen.
         */
        void initLBL();

        /**
         * @brief Initializes the buttons for replaying, accessing settings, and leaving.
         */
        void initBTN();

    signals:
        /**
         * @brief Signal emitted when the replay button is clicked.
         */
        void replay();

        /**
         * @brief Signal emitted when the settings button is clicked.
         */
        void settings();

        /**
         * @brief Signal emitted when the leave button is clicked.
         */
        void leave();
    };
}

#endif //GAMEOVERVIEW_H
