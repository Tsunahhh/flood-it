#ifndef GRID_H
#define GRID_H

#include <vector>
#include "Colors.h"

/**
 * @file Grid.h
 * @brief Defines the Grid class, which represents the game grid for the Flood-It game.
 *
 * The Grid class manages the grid of colored cells and provides methods to manipulate and query the game state.
 */

namespace model {

    /**
     * @class Grid
     * @brief The Grid class represents the grid in the Flood-It game, handling the game's logic and cell colors.
     *
     * The Grid class manages the game grid, which is composed of cells of different colors. It provides methods
     * to access and change the color of the cells, check the game status, and handle color change operations.
     */
    class Grid {

        const int _rows; ///< Number of rows in the grid.
        const int _cols; ///< Number of columns in the grid.
        const int _nbColors; ///< Number of different colors used in the grid.
        std::vector<std::vector<Color>> _grid; ///< 2D vector representing the grid's cells and their colors.

        /**
         * @brief Generates the grid with random colors.
         *
         * This internal method is used to initialize the grid with random colors based on the number of colors.
         */
        void genGrid();

        /**
         * @brief Recursively changes the color of adjacent cells.
         *
         * This method performs a recursive flood-fill algorithm to change the color of cells that are connected
         * to the target cell and have the same initial color.
         *
         * @param x The x-coordinate (row) of the starting cell.
         * @param y The y-coordinate (column) of the starting cell.
         * @param oldColor The initial color of the cell being changed.
         * @param newColor The new color to apply to the connected cells.
         */
        void reccChange(const int &x, const int &y, const Color &oldColor, const Color &newColor);

    public:
        /**
         * @brief Constructs a Grid object with the specified dimensions and number of colors.
         *
         * @param rows The number of rows in the grid.
         * @param cols The number of columns in the grid.
         * @param nbColors The number of distinct colors to be used in the grid.
         */
        Grid(const int &rows, const int &cols, const int &nbColors);

        /**
         * @brief Retrieves the color of a specific cell in the grid.
         *
         * @param x The x-coordinate (row) of the cell.
         * @param y The y-coordinate (column) of the cell.
         * @return The Color of the specified cell.
         */
        Color getColor(const int &x, const int &y) const;

        /**
         * @brief Plays a color on the grid, changing the connected cells of the same color.
         *
         * This method triggers the color change on the grid, applying the new color to the connected cells
         * starting from the top-left corner of the grid.
         *
         * @param color The new Color to apply.
         */
        void playColor(const Color &color);

        /**
         * @brief Returns the number of rows in the grid.
         *
         * @return The number of rows in the grid.
         */
        int getRows() const;

        /**
         * @brief Returns the number of columns in the grid.
         *
         * @return The number of columns in the grid.
         */
        int getCols() const;

        /**
         * @brief Checks if all cells in the grid are of the same color.
         *
         * @return True if all cells are the same color, false otherwise.
         */
        bool isAllSame() const;
    };
}

#endif //GRID_H
