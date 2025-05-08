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

    char input;
    rat.findPosition(maze);
    while (true) {
        system("cls");
        maze.printMaze();
        std::cout << "Move (w/a/s/d, q to quit): ";
        std::cin >> input;
        if (input == 'q') break;

        rat.move(input, maze);
    }

    return 0;
}