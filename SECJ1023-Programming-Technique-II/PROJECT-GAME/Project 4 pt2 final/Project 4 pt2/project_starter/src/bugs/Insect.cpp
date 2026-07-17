#include "Insect.hpp"
#include "../player/Player.hpp" 
#include <graphics.h>

Insect::Insect(int startX, int startY, int spd, int hp, int pts, int col) {
    x = startX;
    y =startY;
    speed =spd;
    health = hp;
    points = pts;

    color = col;
    alive = true;
    radius = 20; 

}

Insect::~Insect() {}
int Insect::getX() const { 
    return x; }
void Insect::setX(int startX) { 
    x = startX; }
int Insect::getY() const { 
    return y; }
void Insect::setY(int startY) { 
    y = startY; }
int Insect::getSpeed() const { 
    return speed; }
void Insect::setSpeed(int spd) { 
    speed = spd; }
int Insect::getHealth() const { 
    return health; }
void Insect::setHealth(int hp) { 
    health = hp; }
int Insect::getPoints() const { 
    return points; }
void Insect::setPoints(int pts) { 
    points = pts; }
    
bool Insect::isAlive() const { 
    return alive; }
void Insect::setAlive(bool status) { 
    alive = status; }
int Insect::getRadius() const { 
    return radius; }
void Insect::setRadius(int r) { 
    radius = r; }
int Insect::getColor() const { 
    return color; }
void Insect::setColor(int col) { 
    color = col; }

void Insect::resetPosition() {
    y = 0;
    alive = true;

}

void Insect::move() {
    y += speed;
}

void Insect::draw() {
    if (alive) {
        setcolor(color);
        setfillstyle(SOLID_FILL,color);
        fillellipse(x,y,radius,radius);
    }
}

void Insect::getHitByPlayer(Player* player) {
    health--;

    PlaySound(TEXT("assets/audio/bug_hit.wav"), NULL, SND_ASYNC | SND_FILENAME);
    if (health <= 0) {
        alive = false;
        player->addScore(points); 
    }
}

bool Insect::isHit(int mx, int my) {
    return (mx >= x && mx <= x + 80 && my >= y && my <= y + 80);
}

void Insect::setDead() {
    alive = false;
}