#include <iostream>
#include "Maze.hpp"

bool Maze::isWalkable(int x, int y) const {
    return x >= 0 && x < rows && y >= 0 && y < cols && maze1[x][y] == 0;
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
