#pragma once
#include "Direction.h"

class Player;
class MovementManager{
    private:
        Player& playerLink;
    public:
        MovementManager(Player& player);
        void move(Direction direction);
};