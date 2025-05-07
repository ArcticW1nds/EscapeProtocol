#ifndef MAZE_HPP
#define MAZE_HPP

const int rows = 10;
const int cols = 11;

class Maze {
public:
    int maze1[rows][cols] = {
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

    bool isWalkable(int x, int y) const;
    void printMaze() const;
};

#endif
