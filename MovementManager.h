#ifndef MovementManager_h
#define MovementManager_h
#include "Direction.h"
#include "Field/Field.h"
#include <iostream>
class Player;
class MovementManager{
    private:
        Player& playerLink;
        std::pair<int,int> coordinates;
        Field& field;
        void setCoordinates(int x, int y);
        bool check(int x, int y);
    public:
        MovementManager(Player& playerLink, Field& field, int x = 0, int y = 0);
        void move(Direction direction);
        void operator=(MovementManager other);
        std::pair<int,int> getCoordinates() const;
        void teleport(std::pair<int,int> coordinate);
        Player& getPlayer();
        Field& getField();
        void FieldView();
        
};

#endif