#include <iostream>
#include "Inventory.h"
#ifndef Inventory_cpp
#define Inventory_cpp


Inventory::Inventory(): flask (new Flask), powerPotion (new PowerPotion){};
Inventory::~Inventory(){
    delete flask;
    delete powerPotion;
}

void Inventory::showInventory()
{
    std::cout << "В вашем инвентаре\n"
                << this->flask->getCount() << " зелья лечения\n"
                << this->powerPotion->getCount() << " зелий силы\n";
}

PowerPotion& Inventory::getPowerPotion() { return *(this->powerPotion); }
Flask& Inventory::getFlask() { return *(this->flask); }

#endif