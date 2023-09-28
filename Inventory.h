#include <iostream>
#pragma once
#include "Flask.h"
#include "Player.h"
#include "TPScroll.h"
#include "PowerPotion.h"


class Inventory
{
    
public:
    Flask* const flask;
    TPScroll* const tpscroll;
    PowerPotion*const  powerPotion;
    Inventory();
    void showInventory();
};