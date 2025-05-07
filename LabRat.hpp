#ifndef LABRAT_HPP  
#define LABRAT_HPP  
#include "maze.hpp"  
#include "maze.cpp"  
class LabRat {  
private:  
   int health;  
   int power;  
   int x;  
   int y;  
public:  
   LabRat(int health, int power, int startX, int startY) : health(health), power(power), x(startX), y(startY) {}  
 
   void move(char direction, const Maze& maze) {  
       int newX = x;  
       int newY = y;  
 
       switch (direction) {  
           case 'w': newX--; break;  
           case 's': newX++; break;  
           case 'a': newY--; break;  
           case 'd': newY++; break;  
           default: std::cout << "Invalid move\n"; return;  
       }  
 
       if (maze.isWalkable(newX, newY)) {  
           x = newX;  
           y = newY;  
       }  
       else {  
           std::cout << "Blocked!" << std::endl;  
       }  
   }  
 
   int getX() const { return x; }  
   int getY() const { return y; }  
   void dash(int row, int collum);  
};  
 
#endif