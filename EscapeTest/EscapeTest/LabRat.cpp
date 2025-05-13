#include <iostream>
#include "LabRat.hpp"
#include "Maze.hpp"


LabRat::LabRat(int h, int p, int s) {
    health = h;
    power = p;
    speed = s;
    dmgMult = 1.0;
    canTakeTurn = true;
    int tileUnderneath;
    x = 0;
    y = 0;
}

const char* LabRat::getName() const {
    return "Lab Rat";
}

void LabRat::takeTurn(Combatant* opponent) {
    if (!canTakeTurn) {
        std::cout << "You are stunned! You lose your turn.\n";
        return;
    }

    int baseDamage = getPower();

    std::cout << "(1) Physical Attack\n";
    std::cout << "(2) Activate Skill\n";
    int c2 = getValidatedInput(1, 2);

    if (c2 == 1) {
        std::cout << "Choose Move\n";
        std::cout << "(1) Bite (bp-40)\n(2) Scratch (bp-10) (8x multi-hit)\n";
        int c1 = getValidatedInput(1, 2);

        if (c1 == 1) {
            std::cout << getName() << " uses Bite!\n";
            dealDamage(opponent, baseDamage * 4);
        }
        else {
            std::cout << getName() << " uses Scratch!\n";
            multiHitAttack(opponent, baseDamage / 2, 8);
        }

    }
    else {
        std::cout << "Choose Move\n";
        std::cout << "(1) Plague (opponent dies after 3 turns)\n(2) Bravery (1.75x dmg multiplier)\n";
        int c3 = getValidatedInput(1, 2);

        if (c3 == 1) {
            plagueActive = true;
        }
        else {
            setDmgMult(1.5);
        }
    }
    //at the end of your turn, regardless of stun, check if plague has been activated
    if (plagueActive == true) {
        plagueCounter++;
        std::cout << "Plague Counter: " << plagueCounter << std::endl;
        if (plagueCounter >= 3) {
            std::cout << opponent->getName() << " has succumbed to the plague!\n";
            dealDamage(opponent, opponent->getHealth());
        }
    }
}

void LabRat::findPosition(const Maze& maze) {  
   for (int i = 0; i < maze.rows; ++i) { // Use instance reference instead of Maze::rows  
       for (int j = 0; j < maze.cols; ++j) { // Use instance reference instead of Maze::cols  
           if (maze.maze1[i][j] == 2) {  
               x = i;  
               y = j;  
               tileUnderneath = 2;  
               maze.maze1[i][j] = 9;  
               return;  
           }  
       }  
   }  
   std::cerr << "rat not found in maze!\n";  
}
bool LabRat::atGoal() const
{
    return tileUnderneath == 3;
}
void LabRat::move(char direction, const Maze& maze)
{
    int newX = x;
    int newY = y;

    switch (direction) {
    case 'w': newX--; break; // up
    case 's': newX++; break; // down
    case 'a': newY--; break; // left
    case 'd': newY++; break; // right
    default:
        std::cout << "Invalid direction input. Use w/a/s/d.\n";
        return;
    }

    if (maze.isWalkable(newX, newY)) {
        maze.maze1[x][y] = tileUnderneath;
        tileUnderneath = maze.maze1[newX][newY];
        x = newX;
        y = newY;
        maze.maze1[x][y] = 9;
        std::cout << "Moved to (" << x << ", " << y << ")\n";
    }
    else {
        std::cout << "Blocked! Can't move to (" << newX << ", " << newY << ")\n";
    }
}
