#ifndef INSECT_HPP
#define INSECT_HPP

class Player; 

class Insect {
protected: 
    int x, y;
    int speed;
    int health;
    int points;
    bool alive;
    int radius; 
    int color;

public:
    Insect(int startX, int startY, int spd, int hp, int pts, int col);
    virtual ~Insect(); 

    int getX() const;
    void setX(int startX);

    int getY() const;
    void setY(int startY);
    int getSpeed() const;
    void setSpeed(int spd);
    int getHealth() const;
    void setHealth(int hp);
    int getPoints() const;
    void setPoints(int pts);
    bool isAlive() const;
    void setAlive(bool status);
    int getRadius() const;
    void setRadius(int r);
    int getColor() const;
    void setColor(int col);

    void resetPosition();
    
    virtual void move();       
    virtual void draw();       
    virtual void getHitByPlayer(Player* player); 
    
    bool isHit(int mx, int my);
    void setDead();
};
#endif