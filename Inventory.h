#include <iostream>
#ifndef Inventory_h
#define Inventory_h
#include "Flask.h"
#include "Player.h"
#include "PowerPotion.h"


class Inventory
{
    
public:
    Flask* const flask;
    PowerPotion*const  powerPotion;
    Inventory();
    void showInventory();
};
#endif