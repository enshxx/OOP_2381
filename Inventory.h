#include <iostream>
#ifndef Inventory_h
#define Inventory_h
#include "Items/Flask.h"
#include "Player.h"
#include "Items/PowerPotion.h"

class Inventory
{
private:
    Flask* flask;
    PowerPotion* powerPotion;
public:
    Inventory();
    ~Inventory();
    Flask& getFlask();
    PowerPotion& getPowerPotion();
    Inventory& operator=(Inventory other) = delete;
    void showInventory();
};
#endif