#ifndef SETTINGS_H
#define SETTINGS_H

/**
 * @file Settings.h
 * @brief Defines the Settings structure for game configuration parameters.
 */

namespace model {

    /**
     * @struct Settings
     * @brief Represents the configuration settings for the game.
     *
     * The Settings structure holds the parameters that define the game's configuration,
     * including the dimensions of the game grid, the number of colors available, and the player's score.
     */
    struct Settings {
        int width{10};    ///< Width of the game grid.
        int height{10};   ///< Height of the game grid.
        int colors{6};    ///< Number of colors available in the game.
        int score{0};     ///< Current score of the player.
    };
}

#endif //SETTINGS_H
