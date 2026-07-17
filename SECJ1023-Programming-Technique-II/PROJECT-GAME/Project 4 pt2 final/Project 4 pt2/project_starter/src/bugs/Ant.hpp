#ifndef ANT_HPP
#define ANT_HPP
#include "Insect.hpp"

class Ant : public Insect {
public:
    Ant(int startX, int startY, int speedBoost);

    void draw();
};
#endif