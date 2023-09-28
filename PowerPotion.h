#pragma once
#include "Item.h"
class Plaeyr;

class PowerPotion: public Item
{
    public:
        PowerPotion(std::string name = "PowerPotion", int count = 0);
        void use(Player& player);
};