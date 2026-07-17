#ifndef GAME_HPP
#define GAME_HPP

#include "../bugs/Insect.hpp" 
#include "../ui/Scoreboard.hpp" 
#include "../player/Player.hpp"
#include <vector>

using namespace std;

class Game {
private:
    int gameState; 
    vector<Insect*> swarm; 
    Scoreboard ui;         
    Player player;         

public:
    Game();
    ~Game(); 
    void spawnInsect();
    void checkCollisions();
    void updateScreen();
    void resetGame();
    void run();
};
#endif