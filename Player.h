#ifndef Player_h
#define Player_h
#include <iostream>
#define MIN_HEALTH 0
#define MIN_SCORE 0
#define MIN_POWER 10
#define MAX_HEALTH 1000
class Inventory;

class Player
{
private:
    int power, score, health;
    bool dead;
    Inventory* inv;

public:
    Player(int power = MIN_POWER, int score = MIN_SCORE, int health = MIN_HEALTH);
    ~Player();
    Inventory& getInventory();
    void setHealth(int hp);
    void setScore(int newScore);
    void setPower(int newPower);
    bool isDead() const;
    int getHealth() const;
    int getScore() const;
    int getPower() const;
    void operator=(Player other);
};
#endif