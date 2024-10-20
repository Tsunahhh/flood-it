//
// Created by tsuna on 24/09/24.
//

#ifndef COLORS_H
#define COLORS_H

namespace model {
    struct Color {
        static constexpr int RED{0};
        static constexpr int GREEN{1};
        static constexpr int YELLOW{2};
        static constexpr int ORANGE{3};
        static constexpr int PURPLE{4};
        static constexpr int CYAN{5};
        static constexpr int BLUE{6};
        static constexpr int ROSE{7};
        static constexpr int BLACK{8};
        static constexpr int WHITE{9};

        int value;

        Color(const int value) : value(value) {}

        int getIdValue() const {
            return this->value;
        }

        bool operator==(const Color & color) const {
            return value == color.value;
        };

    };
}

#endif //COLORS_H
