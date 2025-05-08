#include <iostream>
#include <string>
#include "JRPG.hpp"
#include "Scientist.hpp"
#include "LabRat.hpp"

int main() {
    Maze maze;
    LabRat rat(10000, 10, 5);
    //Scientist cornifer(120, 50, 4);
    //(&rat, &cornifer);

    maze.printMaze();
    rat.findPosition(maze);
    rat.move('w', maze);
    maze.printMaze();

    return 0;
}