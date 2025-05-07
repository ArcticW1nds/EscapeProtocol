#include <iostream>
#include "LabRat.hpp"
#include "JRPG.hpp"  // For ranNumGen and getValidatedInput

LabRat::LabRat(int h, int p, int s) {
    health = h;
    power = p;
    speed = s;
    dmgMult = 1.0;
    canTakeTurn = true;
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