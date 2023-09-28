#include <iostream>
#include "Item.h"
#include "Player.h"
#ifndef Item_cpp
#define Item_cpp



void Item::setCount(int count) { this->count = count; }
void Item::setName(std::string name) { this->name = name; }
int Item::getCount() { return this->count; }
std::string Item::getName() { return this->name; }


#endif