//
// Created by tsuna on 24/09/24.
//
#include "Grid.h"

#include <algorithm>
#include <iostream>
#include <vector>
#include <random>

model::Grid::Grid(const int & rows, const int & cols, const int & nbColors) :
        _rows(rows), _cols(cols), _nbColors(nbColors)
{
    std::cout << "Grid created" << std::endl;
    _grid = std::vector<std::vector<Color>>(rows, std::vector<Color>(cols, Color(0)));
    genGrid();
}

model::Color model::Grid::getColor(const int & x, const int & y) const {
    return _grid.at(y).at(x);
}

void model::Grid::playColor(Color color) {
    Color oldColor = _grid.at(0).at(0);

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

void model::Grid::genGrid() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, _nbColors - 1);

    std::ranges::for_each(_grid, [&](std::vector<Color>& v) {
        std::ranges::generate(v.begin(), v.end(), [&]() {
            return Color(dis(gen));
        });
    });

    for (auto line : _grid) {
        for (auto color : line) {
            std::cout << color.value;
        }
        std::cout << std::endl;
    }
}
