#include <iostream>
#include "Inventory.h"
#ifndef Inventory_cpp
#define Inventory_cpp


Inventory::Inventory()
{
    Flask flask;
    TPScroll tpscroll;
    PowerPotion powerPotion;
    this->flask = flask;
    this->tpscroll = tpscroll;
    this->powerPotion = powerPotion;
}

void Inventory::showInventory()
{
    std::cout << "В вашем инвентаре\n"
                << this->flask.getCount() << " зелья лечения\n"
                << this->tpscroll.getCount() << " свитка телепортации\n"
                << this->powerPotion.getCount() << " зелий силы\n";
}

void Inventory::useItem(std::string name, Player &player)
{
    if (name == "Flask")
    {
        this->flask.use(player);
    }
    else if (name == "TPScroll")
    {
        this->tpscroll.use(player);
    }
    else if(name == "PowerPotion")
    {
        this->powerPotion.use(player);
    }
    else
    {
        std::cout << "You don't have this item" << std::endl;
    }
}

void Inventory::addItem(std::string name)
{
    if (name == "Flask")
    {
        this->flask.setCount(this->flask.getCount() + 1);
    }
    else if (name == "TPScroll")
    {
        this->tpscroll.setCount(this->tpscroll.getCount() + 1);
    }
    else if (name == "PowerPotion")
    {
        this->powerPotion.setCount(this->powerPotion.getCount() + 1);
    }
    else
    {
        std::cout << "Incorrect name" << std::endl;
    }
    
}



#endif