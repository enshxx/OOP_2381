#pragma once
#include "Item.h"
class Player;


class TPScroll : public Item
{
public:
    TPScroll(std::string name = "TPScroll", int count = MIN_COUNT);
    void use(Player& player);
};