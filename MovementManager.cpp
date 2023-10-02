#include "MovementManager.h"
#include "Player.h"
#ifndef MovementManager_cpp
#define MovementManager_cpp

MovementManager::MovementManager(Player &playerLink, Field &field, int x, int y) : playerLink(playerLink), field(field)
{
    this->setCoordinates(x, y);
};

std::pair<int, int> MovementManager::getCoordinates() { return this->coordinates; }
void MovementManager::setCoordinates(int x, int y)
{
    this->coordinates = std::make_pair(x, y);
}

bool MovementManager::check(int x, int y)
{
    return (x >= 0 && x < this->field.getWidth() && y >= 0 && y < this->field.getHeight() && this->field.getCell(x, y).getCellPatency() == true);
}
void MovementManager::move(Direction direction)
{
    int new_x = this->coordinates.first, new_y = this->coordinates.second;
    switch ((direction))
    {
    case (Direction::right):
        new_x++;
        break;
    case (Direction::left):
        new_x--;
        break;
    case (Direction::up):
        new_y++;
        break;
    case (Direction::down):
        new_y--;
        break;
    }

    if (check(new_x, new_y))
        this->setCoordinates(new_x, new_y);
}
void MovementManager::operator=(MovementManager other){};
#endif