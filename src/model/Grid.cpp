//
// Created by tsuna on 24/09/24.
//
#include "../../include/Grid.h"

#include <algorithm>
#include <vector>

model::Grid::Grid(const int rows, const int cols, const char nbColors) :
        _rows(rows), _cols(cols), _nbColors(nbColors)
{

    _grid = std::vector<std::vector<int>>(rows, std::vector<int>(cols, 0));
    std::ranges::for_each(_grid, [](std::vector<int>& v) {
        std::ranges::generate(v, std::rand);
    });
}
char model::Grid::getColor(int x, int y) {
    return _grid.at(y).at(x);
}

void model::Grid::playColor(model::Color color) {

}