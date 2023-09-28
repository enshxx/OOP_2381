#pragma once
#include <iostream>
class Inventory;

class Player
{
private:
    int power, score, health;
    std::pair <int,int> coordinates;
    bool dead;

public:
    Inventory* const inv;
    Player(int power = 10, int score = 0, int health = 100);
    void setHealth(int hp);
    void setScore(int newScore);
    void setPower(int newPower);
    void setCoordinates(int x, int y);
    bool isDead();
    std::pair<int, int> getCoordinates();
    int getHealth();
    int getScore();
    int getPower();
};