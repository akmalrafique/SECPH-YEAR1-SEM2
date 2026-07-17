#ifndef BEE_HPP
#define BEE_HPP
#include "Insect.hpp"

class Bee : public Insect {
private:
    float angle;
    int startXPos;

public:
    Bee(int sX, int startY, int speedBoost);
    void move() override;
    void getHitByPlayer(Player* player) override;
    void draw();
};
#endif