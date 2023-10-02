#include <iostream>
#ifndef Item_h
#define Item_h
#define MIN_COUNT 0
class Player;


class Item
{
private:
    int count;

public:
    virtual void use(Player& player) = 0;
    void setCount(int count = MIN_COUNT);
    int getCount();
};
#endif