#pragma once
#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>

class Map {
public:
    Map(int width, int height);
    void display() const;
    void addCharacter(int x, int y, char symbol);
    void moveCharacter(int oldX, int oldY, int newX, int newY, char symbol);

private:
    std::vector<std::vector<char>> grid;
    int width;
    int height;
};

#endif

