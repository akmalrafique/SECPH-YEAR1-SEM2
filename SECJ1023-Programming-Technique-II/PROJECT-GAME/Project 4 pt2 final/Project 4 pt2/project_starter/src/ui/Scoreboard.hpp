#ifndef SCOREBOARD_HPP
#define SCOREBOARD_HPP

class Scoreboard {
private:
    int currentScore;
    int currentLives;

public:
    Scoreboard();
    ~Scoreboard();

    int getCurrentScore() const;
    void setCurrentScore(int score);
    int getCurrentLives() const;
    void setCurrentLives(int lives);

    void reset();

    void addScore(int points);
    void loseLife();
    int checkButtonClicks(int mx, int my);

    void drawHUD(int score, int lives);
    void drawGameOverScreen(int finalScore);
};

#endif