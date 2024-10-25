#ifndef SETTINGSVIEW_H
#define SETTINGSVIEW_H

#include <QWidget>
#include <QSpinBox>
#include <QCheckBox>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

#include "Settings.h"

/**
 * @file SettingsView.h
 * @brief Defines the SettingsView class for configuring game settings.
 */

namespace view {

    /**
     * @class SettingsView
     * @brief A widget for adjusting game settings.
     *
     * The SettingsView class provides an interface for users to modify game settings,
     * including the width, height, and number of colors in the game. It contains input fields
     * for these parameters and buttons to play or leave the settings view.
     */
    class SettingsView : public QWidget {
    Q_OBJECT

        static const int MAX_SIZE{80};      ///< Maximum size for grid dimensions.
        static const int MIN_SIZE{2};       ///< Minimum size for grid dimensions.
        static const int DEFAULT_WIDTH{10};  ///< Default width for the grid.
        static const int DEFAULT_HEIGHT{10}; ///< Default height for the grid.
        static const int MAX_COLORS{10};    ///< Maximum number of colors allowed.
        static const int MIN_COLORS{3};     ///< Minimum number of colors allowed.

        QGridLayout *_settingsLayout;        ///< Layout for the settings widget.

        QLabel *_settingsLBL;                ///< Label for the settings section.
        QLabel *_widthLBL;                   ///< Label for the width input.
        QLabel *_heightLBL;                  ///< Label for the height input.
        QLabel *_colorsLBL;                  ///< Label for the colors input.

        QSpinBox *_widthSB;                  ///< Spin box for selecting width.
        QSpinBox *_heightSB;                 ///< Spin box for selecting height.
        QSpinBox *_colorsSB;                 ///< Spin box for selecting number of colors.

        QPushButton *_playBT;                ///< Button to start the game.
        QPushButton *_leaveBT;               ///< Button to exit the settings view.

    public:
        /**
         * @brief Constructs a SettingsView object.
         * @param parent The parent widget.
         */
        explicit SettingsView(QWidget *parent = nullptr);

        /**
         * @brief Initializes the labels for the settings inputs.
         */
        void initLabels();

        /**
         * @brief Initializes the settings input fields and layout.
         */
        void initSettings();

        /**
         * @brief Gets the current settings from the input fields.
         * @return The current settings configured by the user.
         */
        model::Settings getSettings();

        /**
         * @brief Destructor for the SettingsView class.
         */
        ~SettingsView();

    signals:
        /**
         * @brief Emitted when the play button is clicked.
         */
        void play();

        /**
         * @brief Emitted when the leave button is clicked.
         */
        void leave();
    };
}

#endif //SETTINGSVIEW_H
