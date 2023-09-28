#pragma once
#include "Item.h"

class Player;

class PowerPotion: public Item
{
    public:
        PowerPotion(std::string name = "PowerPotion", int count = MIN_COUNT);
        void use(Player& player);
};