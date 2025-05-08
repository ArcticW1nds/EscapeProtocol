#include <iostream>
#include <string>

#include "Scientist.hpp"

Scientist::Scientist(int h, int p, int s) {
    health = h;
    power = p;
    speed = s;
    dmgMult = 1.0;
    canTakeTurn = true;
}

const char* Scientist::getName() const {
    return "Scientist";
}


void Scientist::takeTurn(Combatant* opponent) {
    int baseDamage = getPower();
    std::cout << getName() << " attacks!\n";
    dealDamage(opponent, baseDamage);
}