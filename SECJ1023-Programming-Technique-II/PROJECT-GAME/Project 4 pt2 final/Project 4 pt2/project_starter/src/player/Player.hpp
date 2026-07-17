#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>

class Insect; 

class Player {
private: 
    int score;
    int lives;
    int clickX;
    int clickY;

public:
    Player();
    
    int getScore() const;
    int getLives() const;
    void reduceLife();
    void resetStats();
    void addScore(int points); 

    void setClickPosition(int x, int y);
    bool hitObject(Insect* bug);

    void processInput(std::vector<Insect*>& swarm);
};
#endif