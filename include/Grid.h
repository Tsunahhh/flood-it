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
        int _nbColors;
        std::vector<std::vector<Color>> _grid;
        void genGrid();
        void reccChange(int x, int y, Color oldColor);

    public:
        Grid(const int & rows, const int & cols, const int & nbColors);
        Color getColor(const int & x, const int & y) const;
        void playColor(Color color);
        int getRows() const;
        int getCols() const;
        bool isAllSame() const;
    };
}

#endif //GRID_H
