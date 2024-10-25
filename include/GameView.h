#ifndef FLOOD_IT_GAMEVIEW_H
#define FLOOD_IT_GAMEVIEW_H

#include <QGridLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QColor>
#include <vector>

#include "Game.h"
#include "CaseView.h"

/**
 * @file GameView.h
 * @brief Declares the GameView class, which represents the main game interface in the Flood-It game.
 *
 * The GameView class manages the grid of colored cells, handles user interaction, and updates the display based on game state.
 */

namespace view {

    /**
     * @class GameView
     * @brief The GameView class manages the game's visual grid and interactions with the player.
     *
     * GameView provides a visual interface for the game, displays the grid of colored cells,
     * and updates the view in response to player actions and game state changes.
     */
    class GameView : public QWidget {
    Q_OBJECT

        static const int SIZE_WIN{500}; ///< Fixed size of the game window.

        const int _col; ///< Number of columns in the game grid.
        const int _row; ///< Number of rows in the game grid.

        model::Game *_game = nullptr; ///< Pointer to the game logic model.
        QGridLayout *_gridLayout = nullptr; ///< Layout for the game's grid of cells.

        std::vector<std::vector<CaseView*>> _casesRegister; ///< Stores pointers to the CaseView objects representing the grid cells.

    public:
        /**
         * @brief Constructs the GameView, initializing the game grid and UI components.
         *
         * @param game Pointer to the game model.
         * @param parent Pointer to the parent QWidget (optional).
         * @param row The number of rows in the game grid (default is 5).
         * @param col The number of columns in the game grid (default is 5).
         */
        explicit GameView(model::Game *game, QWidget *parent = nullptr, const int & row = 5, const int & col = 5);

        /**
         * @brief Converts a model::Color object into a corresponding QColor object.
         *
         * @param color The model::Color to be converted.
         * @return The corresponding QColor object.
         */
        QColor getQColor(const model::Color &color) const;

        /**
         * @brief Sets the color of a specific cell in the grid.
         *
         * @param x The row index of the cell.
         * @param y The column index of the cell.
         * @param color The QColor to apply to the cell.
         */
        void setColor(const int &x, const int &y, const QColor &color);

        /**
         * @brief Updates the game grid view based on the current game state.
         */
        void updateGameView();

        /**
         * @brief Destructor for GameView. Cleans up dynamically allocated resources.
         */
        ~GameView() override;

    private slots:
        /**
         * @brief Slot that handles a cell click event.
         *
         * When a cell is clicked, this function processes the input and updates the game state.
         *
         * @param x The row index of the clicked cell.
         * @param y The column index of the clicked cell.
         */
        void onCellClicked(const int &x, const int &y);
    };
}

#endif //FLOOD_IT_GAMEVIEW_H
