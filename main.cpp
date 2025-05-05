#include <iostream>
#include <string>
#include "JRPG.hpp"
#include "maze.hpp"

int main() {
    std::cout << "(1) Attack" << std::endl;
    std::cout << "(2) Skill(magic)" << std::endl;


    int AorS = getValidatedInput(1, 2);
    std::cout << AorS;

    return 0;
}