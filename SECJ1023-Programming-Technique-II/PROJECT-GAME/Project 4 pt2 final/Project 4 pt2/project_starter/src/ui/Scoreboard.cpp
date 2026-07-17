#include "Scoreboard.hpp"
#include <graphics.h>
#include <cstdio>

Scoreboard::Scoreboard() {
    currentScore = 0;
    currentLives = 3;
}

Scoreboard::~Scoreboard() {
}
int Scoreboard::getCurrentScore() const {
    return currentScore;
}
void Scoreboard::setCurrentScore(int score) {
    currentScore = score;
}

int Scoreboard::getCurrentLives() const {
    return currentLives;
}

void Scoreboard::setCurrentLives(int lives) {
    currentLives = lives;
}
void Scoreboard::reset() {
    currentScore = 0;
    currentLives = 3;
}

void Scoreboard::addScore(int points) {
    currentScore += points;
}

void Scoreboard::loseLife() {
    if (currentLives > 0) {
        currentLives--;
    }
}

int Scoreboard::checkButtonClicks(int mx, int my) {
    if (mx >= 200 && mx <= 400 && my >= 400 && my <= 450) return 1; 
    if (mx >= 200 && mx <= 400 && my >= 470 && my <= 520) return 2; 
    return 0;
}

void Scoreboard::drawHUD(int score, int lives) {
    currentScore = score;
    currentLives = lives;
    
    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
    setbkcolor(LIGHTGREEN);
    setcolor(BLACK);
    char stats[100];
    sprintf(stats,"Score: %d | Lives: %d",currentScore,currentLives);
    outtextxy(20, 20, stats);

    setcolor(RED);
    line(0,750,600,750);
    outtextxy(250,760,(char*)"PICNIC ZONE");
}

void Scoreboard::drawGameOverScreen(int finalScore) {
    cleardevice();
    setbkcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    bar(0,0,600,800);

    setcolor(RED);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 5);
    int goWidth = textwidth((char*)"GAME OVER");
    outtextxy((600-goWidth) / 2,200, (char*)"GAME OVER");
    

    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    char scoreText[50];
    sprintf(scoreText, "Final Score: %d",finalScore);
    outtextxy(200, 300, scoreText);

    setfillstyle(SOLID_FILL, GREEN);
    bar(200, 400,400, 450);
    outtextxy(230, 415, (char*)"PLAY AGAIN");

    setfillstyle(SOLID_FILL, BLUE);
    bar(200, 470, 400, 520);
    outtextxy(230, 485, (char*)"QUIT GAME");
}