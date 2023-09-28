#pragma once
#include "Direction.h"
#include <iostream>
class Player;
class MovementManager{
    private:
        Player& playerLink;
        std::pair<int,int> coordinates;
        void setCoordinates(int x, int y);
    public:
        MovementManager(Player& player, int x = 0, int y = 0);
        void move(Direction direction);
        
        std::pair<int,int> getCoordinates();
        
};