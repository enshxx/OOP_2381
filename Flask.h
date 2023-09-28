#pragma once
#include <iostream>
#include "Item.h"
class Player;

class Flask : public Item
{
public:
    Flask(std::string name = "Flask", int count = MIN_COUNT);
    void use(Player& player);
};