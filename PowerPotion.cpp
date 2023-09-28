#include "PowerPotion.h"
#include "Player.h"
#ifndef PowerPotion_cpp
#define PowerPotion_cpp



PowerPotion::PowerPotion(std::string name, int count)
{
    this->setName(name);
    this->setCount(count);
}
void PowerPotion::use(Player& player)
{
    if (this->getCount() > 0)
    {
        player.setPower(player.getPower() + 50);
        this->setCount(this->getCount() - 1);
    }
    else
    {
        std::cout << "You don't have PowerPotion" << std::endl;
    }
}

#endif