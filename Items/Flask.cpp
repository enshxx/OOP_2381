#include "Flask.h"
#ifndef Flask_cpp
#define Flask_cpp
#include "../Player.h"

Flask::Flask(int count)
{
    this->setCount(count);
}
void Flask::use(Player &player)
{
    if (this->getCount() > 0)
    {
        player.setHealth(player.getHealth() + 50);
        this->setCount(this->getCount() - 1);
    }
    else
    {
        throw std::invalid_argument("У вас нет этого предмета\n");
    }
}

#endif
