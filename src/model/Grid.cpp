//
// Created by tsuna on 24/09/24.
//
#include "Grid.h"

#include <algorithm>
#include <vector>
#include <random>

#include "Game.h"

model::Grid::Grid(const int & rows, const int & cols, const int & nbColors) :
        _rows(rows), _cols(cols), _nbColors(nbColors)
{
    _grid = std::vector<std::vector<Color>>(rows, std::vector<Color>(cols, Color(0)));
    genGrid();
}

model::Color model::Grid::getColor(const int & x, const int & y) const {
    return _grid.at(y).at(x);
}

void model::Grid::playColor(Color color) {
    const Color oldColor = _grid.at(0).at(0);
    reccChange(0, 0, oldColor, color);
}

int model::Grid::getCols() const {
    return _cols;
}

int model::Grid::getRows() const {
    return _rows;
}

bool model::Grid::isAllSame() const {
    Color pointer = _grid.at(0).at(0);
    int currentRow = 0;
    int currentCol = 1;
    bool allSame = true;
    while (currentRow < _grid.size()) {

        while (currentCol < _grid.at(currentRow).size()) {
            if (pointer.value != getColor(currentCol, currentRow).value) {
                allSame = false;
            }
            currentCol++;
        }

        currentCol = 0;
        currentRow++;
    }

    return allSame;
}

void model::Grid::genGrid() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, _nbColors - 1);

    std::ranges::for_each(_grid, [&](std::vector<Color>& v) {
        std::ranges::generate(v.begin(), v.end(), [&]() {
            return Color(dis(gen));
        });
    });
}

void model::Grid::reccChange(int row, int col, Color oldColor, Color newColor) {
    if (row >= 0 && row < _rows && col >= 0 && col < _cols) {
        if (newColor != oldColor) {
            if (oldColor.getIdValue() == _grid.at(row).at(col).getIdValue()) {
                _grid.at(row).at(col).value = newColor.value;
                reccChange(row + 1, col, oldColor, newColor);
                reccChange(row, col + 1, oldColor, newColor);
                reccChange(row-1, col, oldColor, newColor);
                reccChange(row, col-1, oldColor, newColor);
            }
        }
    }
}