#ifndef SCIENTIST_HPP
#define SCIENTIST_HPP

#include "Combatant.hpp"

class Scientist : public Combatant {
public:
    Scientist(int h, int p, int s);

    const char* getName() const override;
    void takeTurn(Combatant* opponent) override;

private:
    bool plagueActive = false;
    int plagueCounter = 0;
};


#endif 