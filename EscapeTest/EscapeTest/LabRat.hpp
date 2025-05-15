#ifndef LABRAT_HPP
#define LABRAT_HPP

#include "Combatant.hpp"
#include "Maze.hpp"

class LabRat : public Combatant {
public:
    LabRat(int h, int p, int s);

    const char* getName() const override;
    void takeTurn(Combatant* opponent) override;

    void findPosition(Maze& maze);  // not const, since it modifies the maze
    void move(char direction, Maze& maze);
    bool atGoal() const;
    

private:
    int x, y;
    int tileUnderneath;
    bool plagueActive = false;
    int plagueCounter = 0;
    


};

#endif