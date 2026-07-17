#include "Player.hpp"
#include "../bugs/Insect.hpp" 
#include <graphics.h> 

#include <windows.h>
#include <mmsystem.h> 


Player::Player() {
    score = 0;
    lives = 3;
    clickX = 0;
    clickY = 0;
}

int Player::getScore() const { 
    return score; }
int Player::getLives() const { 
    return lives; }
void Player::reduceLife() { 
    lives--; }

void Player::resetStats() { 
    score = 0; 
    lives = 3; 
}

void Player::addScore(int points) {
    score += points;
}

void Player::setClickPosition(int x, int y) {
    clickX = x;
    clickY = y;
}

bool Player::hitObject(Insect* bug) {
    return bug->isHit(clickX, clickY);
}

void Player::processInput(std::vector<Insect*>& swarm) {
    if (ismouseclick(WM_LBUTTONDOWN)) {
        int mx,my;
        getmouseclick(WM_LBUTTONDOWN, mx, my);
        
        setClickPosition(mx, my);
        
        for (int i = 0; i < swarm.size(); i++) {
            if (swarm[i]->isAlive()) {
                if (hitObject(swarm[i])) {
                    swarm[i]->getHitByPlayer(this);
                }
            }
        }
        clearmouseclick(WM_LBUTTONDOWN); 
    }
}