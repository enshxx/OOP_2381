#include <iostream>
#include "Inventory.h"
#ifndef Inventory_cpp
#define Inventory_cpp


Inventory::Inventory(): flask (new Flask), powerPotion (new PowerPotion){};

void Inventory::showInventory()
{
    std::cout << "В вашем инвентаре\n"
                << this->flask->getCount() << " зелья лечения\n"
                << this->powerPotion->getCount() << " зелий силы\n";
}



#endif