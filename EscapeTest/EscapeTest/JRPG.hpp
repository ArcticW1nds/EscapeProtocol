#ifndef JRPG_HPP
#define JRPG_HPP
#include "Scientist.hpp"
#include "LabRat.hpp"

class LabRat;
class Scientist;

void Battle1v1(Combatant* c1, Combatant* c2);

int getValidatedInput(int minRange, int maxRange);

int ranNumGen(int minRange, int maxRange);
int turnOrder();

#endif