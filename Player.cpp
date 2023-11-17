#include <iostream>
#include "Player.h"
#include "Inventory.h"
#ifndef Player_cpp
#define Player_cpp

Player::Player(int power, int score , int health): inv(new Inventory)
    {
        this->setHealth(health);
        this->setPower(power);
        this->setScore(score);
        this->dead = false;
    }
Player::~Player()
{
    delete inv;
}
void Player::setHealth(int hp)
    {
        if (hp >= MIN_HEALTH && hp < MAX_HEALTH)
        {
            this->health = hp;
        }
        else if (hp <= MIN_HEALTH)
        {
            this->dead = true;
        }
        else
        {
            this->health = MAX_HEALTH;
        }
    }
void Player::setScore(int newScore) { this->score = newScore * (newScore > 0); }
void Player::setPower(int newPower) { this->power = newPower * (newPower > 0); }
bool Player::isDead() const{ return this->dead; }
int Player::getHealth() const{ return this->health; }
int Player::getScore() const{ return this->score; }
int Player::getPower() const{ return this->power; }
void Player::operator=(Player other){};
Inventory& Player::getInventory() { return *(this->inv); }
#endif