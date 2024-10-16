//
// Created by tsuna on 24/09/24.
//

#ifndef GRID_H
#define GRID_H
#include <vector>

#include "Colors.h"

namespace model {
    class Grid {

        unsigned _rows;
        unsigned _cols;
        unsigned _nbColors;
        std::vector<std::vector<unsigned>> _grid;
        void genGrid();

    public:
        Grid(const unsigned & rows, const unsigned & cols, const unsigned & nbColors);
        unsigned getColor(const unsigned & x, const unsigned & y) const;
        void playColor(Color color);
        unsigned int getRows() const;
        unsigned int getCols() const;
        bool isAllSame() const;
    };
}
#endif //GRID_H
