#include "Flask.h"
#ifndef Flask_cpp
#define Flask_cpp
#include "Player.h"

Flask::Flask(std::string name, int count)
{
    this->setName(name);
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
        std::cout << "You don't have Flask" << std::endl;
    }
}
#endif
