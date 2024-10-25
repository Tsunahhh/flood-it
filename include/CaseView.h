/**
 * @file CaseView.h
 * @brief Declaration of the CaseView class, which represents an individual tile in the Flood It game interface.
 *
 * This file contains the definition of the CaseView class that manages the display
 * and interactions of a game tile. Each tile has a position and can be colored
 * and clicked by the user.
 */

#ifndef FLOOD_IT_CASEVIEW_H
#define FLOOD_IT_CASEVIEW_H

#include <QWidget>
#include <QPalette>
#include <QMouseEvent>

/**
 * @namespace view
 * @brief Namespace containing all views of the Flood It application.
 *
 * The `view` namespace groups all the classes responsible for displaying
 * the user interface of the game.
 */
namespace view {

    /**
     * @class CaseView
     * @brief Class representing a game board tile.
     *
     * The CaseView class inherits from QWidget and manages the display
     * and events of a tile. Each tile has a position (x, y)
     * and a color, and emits a signal when clicked.
     */
    class CaseView : public QWidget {
    Q_OBJECT

        const int _x; ///< x-coordinate of the tile.
        const int _y; ///< y-coordinate of the tile.

    public:
        /**
         * @brief Constructor for the CaseView class.
         *
         * @param x The x-coordinate of the tile on the game board.
         * @param y The y-coordinate of the tile on the game board.
         * @param color The initial color of the tile.
         * @param parent The parent widget of the tile (can be nullptr).
         */
        CaseView(const int & x, const int & y, const QColor & color, QWidget *parent = nullptr);

        /**
         * @brief Changes the color of the tile.
         *
         * @param color The new color to apply to the tile.
         */
        void setColor(const QColor &color);

    signals:
        /**
         * @brief Signal emitted when the tile is clicked.
         *
         * @param row The x-coordinate (row) of the tile.
         * @param col The y-coordinate (column) of the tile.
         */
        void clicked(const int &row, const int &col);

    protected:
        /**
         * @brief Mouse click event handler.
         *
         * This method is called when the user clicks on the tile.
         * It emits the `clicked` signal.
         *
         * @param event Mouse click event.
         */
        void mousePressEvent(QMouseEvent * event) override;
    };

} // namespace view

#endif // FLOOD_IT_CASEVIEW_H
