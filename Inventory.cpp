#include <iostream>
#include "Inventory.h"
#ifndef Inventory_cpp
#define Inventory_cpp


Inventory::Inventory(): flask (new Flask), powerPotion (new PowerPotion),tpscroll (new TPScroll){};

void Inventory::showInventory()
{
    std::cout << "В вашем инвентаре\n"
                << this->flask->getCount() << " зелья лечения\n"
                << this->tpscroll->getCount() << " свитка телепортации\n"
                << this->powerPotion->getCount() << " зелий силы\n";
}



#endif