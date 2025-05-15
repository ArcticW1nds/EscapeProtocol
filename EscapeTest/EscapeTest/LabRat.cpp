#include <iostream>
#include "LabRat.hpp"
#include "Maze.hpp"
#include "Utilities.hpp"
#include "Combatant.hpp"
#include "JRPG.hpp"

LabRat::LabRat(int h, int p, int s) {
    health = h;
    power = p;
    speed = s;
    dmgMult = 1.0;
    canTakeTurn = true;
    plagueActive = false;
    plagueCounter = 0;
    x = 0;
    y = 0;
    tileUnderneath = 0;
}

const char* LabRat::getName() const {
    return "Lab Rat";
}

void LabRat::takeTurn(Combatant* opponent) {
    if (!canTurnCheck()) {
        std::cout << getName() << " is stunned and cannot take a turn!\n";
        stunManagement();
        return;
    }

    std::cout << "(1) Physical Attack\n(2) Activate Skill\n";
    int choice = getValidatedInput(1, 2);

    if (choice == 1) {
        std::cout << "Choose Move\n(1) Bite (bp-40)\n(2) Scratch (bp-10, 8x)\n";
        int move = getValidatedInput(1, 2);

        if (move == 1) {
            std::cout << getName() << " uses Bite!\n";
            dealDamage(opponent, getPower() * 4);
        }
        else {
            std::cout << getName() << " uses Scratch!\n";
            multiHitAttack(opponent, getPower() / 2, 8);
        }
    }
    else {
        std::cout << "Choose Move\n(1) Plague (3-turn kill)\n(2) Bravery (1.5x dmg)\n";
        int skill = getValidatedInput(1, 2);

        if (skill == 1) {
            plagueActive = true;
        }
        else {
            setDmgMult(1.5);
        }
    }

    stunManagement();

    if (plagueActive) {
        plagueCounter++;
        std::cout << "Plague Counter: " << plagueCounter << std::endl;
        if (plagueCounter >= 3) {
            std::cout << opponent->getName() << " has succumbed to the plague!\n";
            dealDamage(opponent, opponent->getHealth());
        }
    }
}

void LabRat::findPosition(Maze& maze) {
    for (int i = 0; i < maze.getRows(); ++i) {
        for (int j = 0; j < maze.getCols(); ++j) {
            if (maze.getTile(i, j) == 2) {
                x = i;
                y = j;
                tileUnderneath = 2;
                maze.setTile(i, j, 9);  // mark rat's position
                return;
            }
        }
    }
    std::cerr << "Rat not found in maze!\n";
}

bool LabRat::atGoal() const {
    return tileUnderneath == 3;
}

void LabRat::move(char direction, Maze& maze) {
    int newX = x;
    int newY = y;

    switch (direction) {
    case 'w': newX--; break;
    case 's': newX++; break;
    case 'a': newY--; break;
    case 'd': newY++; break;
    default:
        std::cout << "Invalid direction input.\n";
        return;
    }

    if (maze.isWalkable(newX, newY)) {
        maze.setTile(x, y, tileUnderneath);               // restore old tile
        tileUnderneath = maze.getTile(newX, newY);        // remember new tile
        x = newX;
        y = newY;
        maze.setTile(x, y, 9);                             // place rat on new tile
        std::cout << "Moved to (" << x << ", " << y << ")\n";
    }
    else {
        std::cout << "Blocked! Can't move to (" << newX << ", " << newY << ")\n";
    }
}