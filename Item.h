#include <iostream>
#pragma once
class Player;


class Item
{
private:
    std::string name;
    int count;

public:
    virtual void use(Player& player) = 0;
    void setCount(int count);
    void setName(std::string name);
    int getCount();
    std::string getName();
};