#ifndef FLOOD_IT_MAINWINDOW_H
#define FLOOD_IT_MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QStackedLayout>

#include "Game.h"
#include "GameView.h"
#include "SettingsView.h"
#include "GameOverView.h"

/**
 * @file MainWindow.h
 * @brief Defines the MainWindow class which serves as the main interface for the Flood-It game.
 */

namespace view {

    /**
     * @class MainWindow
     * @brief The MainWindow class handles the main game window, managing different views and game flow.
     * 
     * This class is responsible for managing the user interface of the game, including the game view, settings view,
     * and game-over view. It integrates with the Game class to manage game state and updates the UI accordingly.
     */
    class MainWindow : public QMainWindow, public utils::Observer {
    Q_OBJECT

        static const int GAME_SIZE{500}; ///< The size of the game window.

        QHBoxLayout *_horizontalLayout = nullptr; ///< Layout to manage the arrangement of UI elements.
        QWidget *_horizontalWidget = nullptr; ///< Central widget for managing layouts.

        SettingsView *_settingsView = nullptr; ///< View to adjust game settings.
        GameView *_gameView = nullptr; ///< View for the game grid and gameplay.
        GameOverView *_gameOverView = nullptr; ///< View displayed when the game is over.

        model::Game *_game = nullptr; ///< Pointer to the game logic.
        model::Settings _settings; ///< The current settings of the game.

    public:
        /**
         * @brief Constructs a MainWindow object.
         * 
         * Initializes the main window and sets up the layout, game view, settings view, and game over view.
         * 
         * @param parent The parent widget (optional).
         */
        explicit MainWindow(QWidget *parent = nullptr);

        /**
         * @brief Updates the observer when game data changes.
         * 
         * This method is triggered when the observable (Game) changes and updates the UI accordingly.
         */
        void updateObs() override;

        /**
         * @brief Destroys the MainWindow object.
         */
        ~MainWindow();

    signals:
        /**
         * @brief Signal emitted when the game is over.
         * 
         * This signal is used to trigger the transition to the game-over view.
         */
        void signalGameOver();

    public slots:
        /**
         * @brief Slot to handle the leave action.
         * 
         * This method handles the logic for leaving the game and exiting the application.
         */
        void leave();

        /**
         * @brief Slot to handle starting a new game.
         * 
         * This method sets up a new game based on the current settings and switches to the game view.
         */
        void playAGame();

        /**
         * @brief Slot to switch to the settings view.
         * 
         * This method transitions the UI to display the settings view, allowing the player to adjust the game settings.
         */
        void settingsView();

        /**
         * @brief Slot to switch to the game-over view.
         * 
         * This method transitions the UI to display the game-over view when the game ends.
         */
        void gameOverView();
    };
}

#endif //FLOOD_IT_MAINWINDOW_H
