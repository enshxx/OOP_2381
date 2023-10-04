#include <iostream>
#include "Item.h"
#include "../Player.h"
#ifndef Item_cpp
#define Item_cpp



void Item::setCount(int count) { this->count = count; }
int Item::getCount() const { return this->count; }


#endif