#ifndef JRPG_HPP
#define JRPG_HPP
#include "Combatant.hpp"

void Battle1v1(Combatant* c1, Combatant* c2);

int getValidatedInput(int minRange, int maxRange);

int turnOrder();

#endif