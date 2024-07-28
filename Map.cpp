#include "Map.h"
#include <iostream>

Map::Map(int width, int height) : width(width), height(height) {
    grid.resize(height, std::vector<char>(width, '.'));
}

void Map::display() const {
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            std::cout << cell << ' ';
        }
        std::cout << '\n';
    }
}

void Map::addCharacter(int x, int y, char symbol) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        grid[y][x] = symbol;
    }
}

void Map::moveCharacter(int oldX, int oldY, int newX, int newY, char symbol) {
    if (newX >= 0 && newX < width && newY >= 0 && newY < height) {
        grid[oldY][oldX] = '.';
        grid[newY][newX] = symbol;
    }
}
