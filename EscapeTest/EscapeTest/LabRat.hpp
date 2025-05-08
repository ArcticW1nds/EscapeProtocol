#ifndef LABRAT_HPP
#define LABRAT_HPP

#include "Combatant.hpp"
#include "Maze.hpp"

class LabRat : public Combatant {
public:
    LabRat(int h, int p, int s);

    const char* getName() const override;
    void takeTurn(Combatant* opponent) override;
    void move(char direction, const Maze& maze);
    void findPosition(const Maze& maze);
   // void dealDamage(Combatant* opponent, int baseDamage);

private:
    int x;
    int y;
    bool plagueActive = false;
    int plagueCounter = 0;
};

#endif 