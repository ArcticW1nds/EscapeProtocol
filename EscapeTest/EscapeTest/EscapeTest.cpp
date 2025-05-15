#include <iostream>
#include <string>
#include "JRPG.hpp"
#include "Scientist.hpp"
#include "LabRat.hpp"
#include "Maze.hpp"

int main() {
    Maze maze1("maze1");
	Maze maze2("maze2");
    LabRat rat(10000, 10, 5);
    Scientist cornifer(120, 50, 4);
 
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
        std::cin >> input;
        if (input == 'q') break;

		rat.move(input, maze1);
    }



   // char input;
   // rat.findPosition(maze2);
   // while (true) {
   //     system("cls");
   //     maze2.printMaze();
   //     if (rat.atGoal()) {
   //         std::cout << "LabRat has reached the goal!\n";
   //         break;
   //     }
   //     std::cout << "Move (w/a/s/d)\n q to quit: ";
   //     std::cin >> input;
   //     if (input == 'q') break;
   //
   //     rat.move(input, maze2);
   // }
   

    Battle1v1(&rat, &cornifer);































    return 0;
}