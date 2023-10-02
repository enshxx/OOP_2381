#include <iostream>
#ifndef Flask_h
#define Flask_h
#include "Item.h"
class Player;

class Flask : public Item
{
public:
    Flask(int count = MIN_COUNT);
    void use(Player& player);
    void operator=(Flask other);
};
#endif