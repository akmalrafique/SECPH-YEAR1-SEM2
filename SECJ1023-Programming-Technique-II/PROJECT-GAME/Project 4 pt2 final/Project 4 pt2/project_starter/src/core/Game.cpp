#include "Game.hpp"
#include "../bugs/Ant.hpp"
#include "../bugs/Beetle.hpp"
#include "../bugs/Bee.hpp"
#include <graphics.h>
#include <cstdlib>
#include <ctime>

Game::Game() {
    gameState = 0;
    srand(time(0));
}

Game::~Game() {
    for (int i = 0; i < swarm.size(); i++) {
        delete swarm[i];
    }
    swarm.clear();
}

void Game::spawnInsect() {
    int currentSpawnRate = 30 - (player.getScore() / 50);
    if (currentSpawnRate < 8) currentSpawnRate = 8; 

    if (rand() % currentSpawnRate == 0) { 
        int startX = 50 + rand() % 500;
        int type = rand() % 100;
        int speedBoost = player.getScore() / 150;
        
        if (type < 60) {
            swarm.push_back(new Ant(startX, 0, speedBoost));
        } else if (type < 85) {
            swarm.push_back(new Beetle(startX, 0, speedBoost));
        } else {
            swarm.push_back(new Bee(startX, 0, speedBoost));
        }
    }
}

void Game::checkCollisions() {
    if (gameState == 0) { 
        player.processInput(swarm);
    } else if (gameState == 1) { 
        if (ismouseclick(WM_LBUTTONDOWN)) {
            int mx, my;
            getmouseclick(WM_LBUTTONDOWN, mx, my);
            
            int action = ui.checkButtonClicks(mx, my);
            if (action == 1) resetGame();
            else if (action == 2) exit(0);
            
            clearmouseclick(WM_LBUTTONDOWN);
        }
    }
}

void Game::updateScreen() {
    if (gameState == 0) {
       cleardevice();
        setfillstyle(SOLID_FILL, WHITE);
        bar(0, 0, 600, 800); 

        spawnInsect();

        for (int i = 0; i < swarm.size(); i++) {
            if (swarm[i]->isAlive()) {
                swarm[i]->move();
                swarm[i]->draw();
                
                if (swarm[i]->getY() > 750) {

                    if (swarm[i]->getPoints() > 0) { 

                    PlaySound(TEXT("assets/audio/lose_health.wav"), NULL, SND_ASYNC | SND_FILENAME);    
                    
                    player.reduceLife();  
                }
                swarm[i]->setDead();
            }
        }
    }

        ui.drawHUD(player.getScore(), player.getLives());
        
        if (player.getLives() <= 0) {
        PlaySound(TEXT("assets/audio/game_over.wav"), NULL, SND_ASYNC | SND_FILENAME);    
        gameState = 1; 
        }

    } else if (gameState == 1) {
        ui.drawGameOverScreen(player.getScore());
    }
}

void Game::resetGame() {
    for (int i = 0; i < swarm.size(); i++) {
        delete swarm[i];
    } 
    swarm.clear();
    player.resetStats(); 
    gameState = 0;
}

void Game::run() {
    initwindow(600, 800, "One Last Picnic"); 

    int page = 0;
        
    while (true) {
     
        setactivepage(page); 
    
        cleardevice();
        checkCollisions();

       
        updateScreen();
        setvisualpage(page);

        page = 1 - page ;

        delay(30); 
    }
    closegraph();
}