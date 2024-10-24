/**
 * @file Game.h
 * @brief Defines the Game class and its core functionality.
 *
 * The Game class represents the main game logic, including the grid, settings, and
 * interaction with the observable pattern for notifying observers of game state changes.
 */

#ifndef GAME_H
#define GAME_H

#include <ostream>
#include <algorithm>
#include "Grid.h"
#include "Observable.h"
#include "Settings.h"

namespace model {

    /**
     * @class Game
     * @brief Manages the game logic, including grid manipulation and observer notification.
     *
     * The Game class represents the main engine of the game. It handles the player's moves,
     * the current state of the grid, and interactions with observers following the observable pattern.
     */
    class Game : public utils::Observable {
        Settings _settings;                 ///< Stores the game settings (e.g., grid size, colors, etc.).
        Grid _grid;                         ///< Represents the game's grid with its current state.
        std::vector<utils::Observer*> _observers; ///< List of observers to notify about game state changes.

    public:
        /**
         * @brief Constructs a new Game object with specified settings.
         *
         * @param settings The settings that define the game's parameters.
         */
        explicit Game(const Settings & settings);

        /**
         * @brief Performs a game move at the specified coordinates.
         *
         * @param x The row coordinate for the move.
         * @param y The column coordinate for the move.
         */
        void play(const int & x, const int & y);

        /**
         * @brief Retrieves the color at the specified grid coordinates.
         *
         * @param x The row coordinate.
         * @param y The column coordinate.
         * @return The color present at the given grid cell.
         */
        Color getColor(const int & x, const int & y) const;

        /**
         * @brief Retrieves the number of rows in the game grid.
         *
         * @return The number of rows in the grid.
         */
        int getRows() const;

        /**
         * @brief Retrieves the number of columns in the game grid.
         *
         * @return The number of columns in the grid.
         */
        int getCols() const;

        /**
         * @brief Gets the current player's state, including score and other settings.
         *
         * @return A Settings object representing the player's state.
         */
        model::Settings getPlayerStates() const;

        /**
         * @brief Checks if all grid cells are filled (game over condition).
         *
         * @return True if all cells are filled, false otherwise.
         */
        bool isAllPlaced() const;

        /**
         * @brief Adds an observer to the observer list.
         *
         * @param obs The observer to add.
         */
        void addObserver(utils::Observer *obs) override;

        /**
         * @brief Removes an observer from the observer list.
         *
         * @param obs The observer to remove.
         */
        void removeObserver(utils::Observer *obs) override;

        /**
         * @brief Notifies all observers of a change in the game state.
         */
        void notifyObserver() override;
    };

}
#endif //GAME_H
