#pragma once
#define MIN_HEALTH 0
#define MIN_SCORE 0
#define MIN_POWER 10
#define MAX_HEALTH 1000
#include <iostream>
class Inventory;

class Player
{
private:
    int power, score, health;
    bool dead;

public:
    Inventory* const inv;
    Player(int power = MIN_POWER, int score = MIN_SCORE, int health = MIN_HEALTH);
    void setHealth(int hp);
    void setScore(int newScore);
    void setPower(int newPower);
    bool isDead();
    int getHealth();
    int getScore();
    int getPower();
};