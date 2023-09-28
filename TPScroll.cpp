#include "TPScroll.h"
#include "Player.h"
#ifndef TPSCroll_cpp
#define TPSCroll_cpp


TPScroll::TPScroll(std::string name, int count)
{
    this->setName(name);
    this->setCount(count);
}
void TPScroll::use(Player& player)
{
    if (this->getCount() > 0)
    {
        // todo (player move to FInal boss)
    }
    else
    {
        std::cout << "You don't have TPScroll" << std::endl;
    }
}


#endif