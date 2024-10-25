/**
 * @file Colors.h
 * @brief Defines the Color struct and its related constants for use in the game model.
 *
 * This file declares the Color struct, which contains several static color constants
 * and provides methods for working with color values in the game.
 */

#ifndef COLORS_H
#define COLORS_H

namespace model {

    /**
     * @struct Color
     * @brief Represents a color using an integer identifier.
     *
     * The Color struct contains predefined static constants for a variety of colors,
     * each identified by a unique integer value. It also provides functionality to
     * compare colors and retrieve the integer ID of the color.
     */
    struct Color {
        /// Predefined color constants represented by integer values.
        static constexpr int RED{0};      ///< Red color id.
        static constexpr int GREEN{1};    ///< Green color id.
        static constexpr int YELLOW{2};   ///< Yellow color id.
        static constexpr int ORANGE{3};   ///< Orange color id.
        static constexpr int PURPLE{4};   ///< Purple color id.
        static constexpr int CYAN{5};     ///< Cyan color id.
        static constexpr int BLUE{6};     ///< Blue color id.
        static constexpr int ROSE{7};     ///< Rose color id.
        static constexpr int BLACK{8};    ///< Black color id.
        static constexpr int WHITE{9};    ///< White color id.

        int value; ///< Holds the current color's integer value.

        /**
         * @brief Constructor for the Color struct.
         *
         * @param value The integer value representing the color.
         */
        Color(const int & value) : value(value) {}

        /**
         * @brief Retrieves the integer ID of the color.
         *
         * @return The integer ID corresponding to the color.
         */
        int getIdValue() const {
            return this->value;
        }

        /**
         * @brief Equality operator to compare two Color objects.
         *
         * @param color The other Color object to compare against.
         * @return True if both Color objects have the same value, false otherwise.
         */
        bool operator==(const Color & color) const {
            return value == color.value;
        };
    };

}

#endif // COLORS_H
