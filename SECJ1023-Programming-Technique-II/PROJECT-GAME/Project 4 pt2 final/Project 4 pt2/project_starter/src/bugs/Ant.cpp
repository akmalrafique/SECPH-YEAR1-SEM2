#include "Ant.hpp"
#include <graphics.h>

Ant::Ant(int startX,int startY,int speedBoost)
    : Insect(startX,startY,3+speedBoost,1,10,BROWN) {}

    void Ant::draw(){
    int currentX = getX(); 
    int currentY = getY();

    readimagefile("assets/image/ant.jpg",currentX,currentY,currentX + 70, currentY + 70);
}