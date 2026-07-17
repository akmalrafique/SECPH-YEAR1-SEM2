#include "Bee.hpp"
#include "../player/Player.hpp"
#include <graphics.h>
#include <cmath>

Bee::Bee(int sX, int startY, int speedBoost) 
    : Insect(sX, startY, 4 + speedBoost, 1, -100, YELLOW) {

    startXPos = sX;
    angle = 0.0;
}
void Bee::move() {
    y += speed;
    angle += 0.2;

    x = startXPos + (50 *sin(angle)); 
}
void Bee::getHitByPlayer(Player* player) {
    health--;
    if (health <= 0) {
        alive = false;

         
        PlaySound(TEXT("assets/audio/lose_health.wav"),NULL, SND_ASYNC | SND_FILENAME);
        player->reduceLife(); 
        player->addScore(points);
    }
}
void Bee::draw() {
    if (alive) {
        readimagefile("assets/image/bee.jpg", x, y, x + 80, y + 80);
    }
}