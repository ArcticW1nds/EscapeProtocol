#include <iostream>
#include <string>

#include "Scientist.hpp"
#include "Utilities.hpp"
#include "JRPG.hpp"

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
    bool check = canTurnCheck();
    if (!check) {
        std::cout << getName() << " is stunned and cannot take a turn!\n";
        stunManagement();
        return;
    }
    else {
        std::cout << "(1) Physical Attack\n";
        std::cout << "(2) Activate Skill\n";
        int c2 = getValidatedInput(1, 2);

        if (c2 == 1) {
            std::cout << "Choose Move\n";
            std::cout << "(1) Lab Explosion(bp-90-big damage, stuns you)\n(2) B**** Slap (30-bp)\n";
            int c1 = getValidatedInput(1, 2);

            if (c1 == 1) {
                std::cout << getName() << " uses Lab Explosion!\n";
                dealDamage(opponent, baseDamage * 9);
                setStunCounter(2);
            }
            else {
                std::cout << getName() << " uses B**** Slap!\n";
                dealDamage(opponent, baseDamage * 3);
            }

        }
        else {
            std::cout << "Choose Move\n";
            std::cout << "(1) Stun Gun(Stun Opponenet, can backfire!)\n(2) Focus (1/2 crit chance)\n";
            int c3 = getValidatedInput(1, 2);

            if (c3 == 1) {
                int backfire = ranNumGen(1, 3);
                if (backfire == 1) {
                    std::cout << "The Stun Gun backfires!\n";
                    setStunCounter(1);
                    opponent->setStunCounter(2);
                }
                else {
                    std::cout << getName() << " uses Stun Gun!\n";
                    opponent->setStunCounter(2);
                }
            }
            else {
                std::cout << getName() << " uses Focus!\n";
                setCritChance(2);
            }
        }
        stunManagement();
    }
}