#pragma once
#include "Combatant.hpp"

class LabRat : public Combatant {
public:
    LabRat(int h, int p, int s);

    const char* getName() const override;
    void takeTurn(Combatant* opponent) override;
   // void dealDamage(Combatant* opponent, int baseDamage);

private:
    bool plagueActive = false;
    int plagueCounter = 0;
};