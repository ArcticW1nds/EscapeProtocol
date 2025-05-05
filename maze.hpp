#ifndef MAZE_HPP
#define MAZE_HPP

#include <iostream>
#include <vector>

const int rows = 10;
const int cols = 11;

class Maze {
private:
	int maze1[rows][cols] = {
	{1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1},//
	{1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1},//
	{1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1},//
	{1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1},//
	{1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1},//
	{1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1},//
	{1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1},//
	{1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1},//
	{1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1},//
	{1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1} //
	};



// 1 = Wall
// 0 = Path
// 2 = Start
// 3 = Exit
	
public:
	bool isWalkable(int x, int y) const {
		return x >= 0 && x < rows && y >= 0 && y < cols && maze1[x][y] == 0;
	}

	void printMaze(int maze[rows][cols]) {
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				if (maze[i][j] == 1) {
					std::cout << "#"; // Wall
				}
				else if (maze[i][j] == 0) {
					std::cout << " "; // Path
				}
				else if (maze[i][j] == 3) {
					std::cout << "E"; // Exit
				}
			}
			std::cout << std::endl;
		}
	}

};

#endif // MAZE_HPP