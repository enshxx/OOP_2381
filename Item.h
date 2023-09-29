#include <iostream>
#ifndef Item_h
#define Item_h
#define MIN_COUNT 0
class Player;


class Item
{
private:
    std::string name;
    int count;

public:
    virtual void use(Player& player) = 0;
    void setCount(int count = MIN_COUNT);
    void setName(std::string name);
    int getCount();
    std::string getName();
};
#endif