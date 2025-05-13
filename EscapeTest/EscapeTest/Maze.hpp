#ifndef MAZE_HPP
#define MAZE_HPP

class Maze {
public:
    static const int rows = 10;
    static const int cols = 11;
    static int maze1[rows][cols];

    bool isWalkable(int x, int y) const;
    void printMaze() const;
};

#endif