#include <iostream>
#include "Player.h"
#include "Inventory.h"
#ifndef Player_cpp
#define Player_cpp

Player::Player(int power, int score , int health):inv(new Inventory)
    {
        this->setHealth(health);
        this->setPower(power);
        this->setScore(score);
        this->dead = false;
        this->coordinates = std::make_pair<int,int> (0,0);
    }
void Player::setHealth(int hp)
    {
        if (hp > 0 && hp < 1000)
        {
            this->health = hp;
        }
        else if (hp <= 0)
        {
            std::cout << "You died" << std::endl;
            this->dead = true;
        }
        else
        {
            this->health = 1000;
        }
    }
void Player::setScore(int newScore) { this->score = newScore * (newScore > 0); }
void Player::setPower(int newPower) { this->power = newPower * (newPower > 0); }
void Player::setCoordinates(int x, int y)
    {
        this->coordinates = std::make_pair(x,y);
    }
bool Player::isDead() { return this->dead; }
std::pair<int, int> Player::getCoordinates() { return this->coordinates; }
int Player::getHealth() { return this->health; }
int Player::getScore() { return this->score; }
int Player::getPower() { return this->power; }

#endif