#pragma once
#include <iostream>
#include "Item.h"
class Player;

class Flask : public Item
{
public:
    Flask(std::string name = "Flask", int count = 0);
    void use(Player& player);
};