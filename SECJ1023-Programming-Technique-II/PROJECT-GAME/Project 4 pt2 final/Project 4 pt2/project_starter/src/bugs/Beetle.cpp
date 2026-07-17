#include "Beetle.hpp"
#include "../player/Player.hpp"
#include <graphics.h>

Beetle::Beetle(int startX, int startY, int speedBoost) 
    : Insect(startX, startY, 1 + speedBoost, 3, 50, DARKGRAY) {}

void Beetle::getHitByPlayer(Player* player) {
    health--;

    PlaySound(TEXT("assets/audio/bug_hit.wav"), NULL, SND_ASYNC | SND_FILENAME);
    
    if (health == 2) color =LIGHTGRAY; 
    if (health == 1) color =RED;
    
    if (health <= 0) {
        alive=false;
        player->addScore(points);
    }
}
void Beetle::draw() {
    if (alive) {

        readimagefile("assets/image/beetletongue.jpg", x, y, x + 90, y + 90);
    }
}
