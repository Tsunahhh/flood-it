//
// Created by tsuna on 24/09/24.
//
#include "../../include/Grid.h"

#include <algorithm>
#include <vector>

model::Grid::Grid(const unsigned & rows, const unsigned & cols, const unsigned & nbColors) :
        _rows(rows), _cols(cols), _nbColors(nbColors)
{

    _grid = std::vector<std::vector<unsigned>>(rows, std::vector<unsigned>(cols, 0));
    std::ranges::for_each(_grid, [](std::vector<unsigned>& v) {
        std::ranges::generate(v, std::rand);
    });
}
unsigned model::Grid::getColor(const unsigned & x, const unsigned & y) const {
    return _grid.at(y).at(x);
}

void model::Grid::playColor(model::Color color) {

}

unsigned int model::Grid::getCols() const {
    return _cols;
}

unsigned int model::Grid::getRows() const {
    return _rows;
}

bool model::Grid::isAllSame() const {
    unsigned pointer = _grid.at(0).at(0);
    unsigned currentRow = 0;
    unsigned currentCol = 1;
    bool allSame = true;
    while (currentRow < _grid.size()) {
        while (currentCol < _grid.at(0).size()) {
            if (pointer != getColor(currentRow, currentCol)) {
                allSame = false;
            }
            currentCol++;
        }
        currentRow++;
    }

    return allSame;
}