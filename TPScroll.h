#pragma once
#include "Item.h"
class Player;


class TPScroll : public Item
{
public:
    TPScroll(std::string name = "TPScroll", int count = 0);
    void use(Player& player);
};