#ifndef BEETLE_HPP
#define BEETLE_HPP
#include "Insect.hpp"

class Beetle : public Insect {
public:
    Beetle(int startX,int startY,int speedBoost);
    
    void getHitByPlayer(Player* player) override;
    void draw();
};
#endif