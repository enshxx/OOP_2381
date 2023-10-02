#include "PowerPotion.h"
#include "../Player.h"
#ifndef PowerPotion_cpp
#define PowerPotion_cpp



PowerPotion::PowerPotion(int count)
{
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
        throw std::invalid_argument("У вас нет этого предмета\n");
    }
}
void PowerPotion::operator=(PowerPotion other) {}
#endif