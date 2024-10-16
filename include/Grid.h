//
// Created by tsuna on 24/09/24.
//

#ifndef GRID_H
#define GRID_H
#include <vector>

#include "Colors.h"

namespace model {
    class Grid {

        int _rows;
        int _cols;
        char _nbColors;
        std::vector<std::vector<int>> _grid;
        void genGrid();

    public:
        Grid(int rows, int cols, char nbColors);
        char getColor(int x, int y);
        void playColor(Color color);
    };
}
#endif //GRID_H
