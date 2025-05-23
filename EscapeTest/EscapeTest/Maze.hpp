//#ifndef MAZE_HPP
//#define MAZE_HPP

//class Maze {
//public:
   
    
//    static const int rows1 = 10;
//    static const int cols1 = 11;
//    static constexpr int rows2 = 30;
//    static constexpr int cols2 = 30;

//    static int maze1[rows1][cols1];
//	static int maze2[rows2][cols2];

//    bool isWalkable(int x, int y) const;
//    void printMaze() const;
//};

//#endif



#ifndef MAZE_HPP
#define MAZE_HPP

#include <vector>
#include <string>

class Maze {
public:
    Maze(const std::string& mazeID);

    bool isWalkable(int x, int y) const;
    void printMaze() const;
    int getRows() const;
    int getCols() const;
    int getTile(int x, int y) const;
    void setTile(int x, int y, int value);
private:
    std::vector<std::vector<int>> grid;
    int rows;
    int cols;

    void loadMaze(const std::string& mazeID);

    // Static maze definitions
    static const std::vector<std::vector<int>> maze1Data;
    static const std::vector<std::vector<int>> maze2Data;
    static const std::vector<std::vector<int>> maze3Data;
};

#endif