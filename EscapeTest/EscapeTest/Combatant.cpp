#include "Combatant.hpp"

#include <iostream>
#include "Utilities.hpp"

int Combatant::getHealth() const { return health; }
void Combatant::takeDamage(int damage) { health -= damage; }
int Combatant::getPower() const { return power; }
int Combatant::getSpeed() const { return speed; }

double Combatant::getDmgMult() const { return dmgMult; }
void Combatant::setDmgMult(double mult) { dmgMult = mult; }

bool Combatant::getCanTakeTurn() const { return canTakeTurn; }
void Combatant::setCanTakeTurn(bool value) { canTakeTurn = value; }

int Combatant::getCritChance() const{return critChance;}
void Combatant::setCritChance(int crit){critChance = crit;}


void Combatant::multiHitAttack(Combatant* opponent, int baseDamage, int hitCount) {
    for (int i = 0; i < hitCount; ++i) {
        dealDamage(opponent, baseDamage);
        std::cout << "Hit " << (i + 1) << "!\n";
    }
}

void Combatant::dealDamage(Combatant* opponent, int baseDamage) {
    int critRoll = ranNumGen(1, critChance);
    int finalDamage = baseDamage;

    if (critRoll == 1) {
        finalDamage *= 2;
        std::cout << "Critical Hit by " << getName() << "!\n";
    }

    if (dmgMult > 1.0) {
        finalDamage = static_cast<int>(finalDamage * dmgMult);
    }

    std::cout << getName() << " deals " << finalDamage << " damage!\n";
    opponent->takeDamage(finalDamage);
}
