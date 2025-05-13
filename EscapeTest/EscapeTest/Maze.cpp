#include <iostream>
#include "Maze.hpp"

int Maze::maze1[rows][cols] = {
        {1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1},
        {1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1}
};

bool Maze::isWalkable(int x, int y) const {
    return x >= 0 && x < rows && y >= 0 && y < cols && maze1[x][y] == 0 || maze1[x][y] == 3;
}

void Maze::printMaze() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            switch (maze1[i][j]) {
            case 1:
                std::cout << "#"; // Wall
                break;
            case 0:
                std::cout << " "; // Path
                break;
            case 2:
                std::cout << "S"; //Start
                break;
            case 3:
                std::cout << "E"; // Exit
                break;
            case 9:
                std::cout << "R"; // Rat
            default:
                //std::cout << "?"; // Unexpected
                break;
            }
        }
        std::cout << '\n';
    }
}
