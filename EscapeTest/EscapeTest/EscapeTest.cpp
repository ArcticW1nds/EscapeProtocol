#include <iostream>
#include <conio.h>
#include <string>
#include "JRPG.hpp"
#include "Scientist.hpp"
#include "LabRat.hpp"
#include "Maze.hpp"

int main() {
    Maze maze1("maze1");
	Maze maze2("maze2");
	Maze maze3("maze3");
    LabRat rat(1000, 10, 5);
    Scientist cornifer(1000, 50, 4);
 
    char input;
    rat.findPosition(maze1);
    while (true) {
        system("cls");
        maze1.printMaze();
        if (rat.atGoal()) {
            std::cout << "LabRat has reached the goal!\n";
            break;
        }
        std::cout << "Move (w/a/s/d)\n q to quit: ";
        char input = _getch();
        if (input == 'q' || input == 'Q') break;

		rat.move(input, maze1);
    }

    //rat.findPosition(maze2);
    //while (true) {
    //    system("cls");
    //    maze2.printMaze();
    //    if (rat.atGoal()) {
    //        std::cout << "LabRat has reached the goal!\n";
    //        break;
    //    }
    //    std::cout << "Move (w/a/s/d)\n q to quit: ";
    //    char input = _getch();
    //    if (input == 'q') break;
    //
    //    rat.move(input, maze2);
    //}
   

    Battle1v1(&rat, &cornifer);



    return 0;
}