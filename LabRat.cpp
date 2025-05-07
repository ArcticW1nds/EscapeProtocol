#include "LabRat.hpp"

class LabRat {
private:
   int health;
   int power;
   int startX;
   int startY;

public:
   LabRat(int health, int power, int startX, int startY) {
       this->health = health;
       this->power = power;
       this->startX = startX;
       this->startY = startY;
   }
};