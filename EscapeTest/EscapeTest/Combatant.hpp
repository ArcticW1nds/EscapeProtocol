#ifndef COMBATANT_HPP
#define COMBATANT_HPP

class Combatant {
protected:
    int health = 0;
    int power = 0;
    int speed = 0;
    double dmgMult = 1.0;
    bool canTakeTurn = true;
    int critChance = 8;

public:
    virtual const char* getName() const = 0;
    virtual void takeTurn(Combatant* opponent) = 0;
    virtual void multiHitAttack(Combatant* opponent, int baseDamage, int hitCount);
    virtual void dealDamage(Combatant* opponent, int baseDamage);

    int getHealth() const;
    void takeDamage(int damage);
    int getPower() const;
    int getSpeed() const;

    double getDmgMult() const;
    void setDmgMult(double mult);

    bool getCanTakeTurn() const;
    void setCanTakeTurn(bool value);

    int getCritChance() const;
    void setCritChance(int crit);

    virtual ~Combatant() {}
};
#endif