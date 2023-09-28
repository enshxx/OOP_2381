#include <iostream>
#pragma once
#include "Flask.h"
#include "Player.h"
#include "TPScroll.h"
#include "PowerPotion.h"


class Inventory
{
private:
    Flask flask;
    TPScroll tpscroll;
    PowerPotion powerPotion;

public:
    Inventory();
    void showInventory();
    void useItem(std::string name, Player &player);
    void addItem(std::string name);
};