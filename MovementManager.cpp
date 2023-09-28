#include "MovementManager.h"
#include "Player.h"
#ifndef MovementManager_cpp
#define MovementManager_cpp

MovementManager::MovementManager(Player &playerLink, int x, int y) : playerLink(playerLink)
{
    this->setCoordinates(x, y);
};

std::pair<int, int> MovementManager::getCoordinates() { return this->coordinates; }
void MovementManager::setCoordinates(int x, int y)
{
    this->coordinates = std::make_pair(x, y);
}

void MovementManager::move(Direction direction)
{
    switch ((direction))
    {
    case (Direction::right):
        this->setCoordinates(this->getCoordinates().first + 1, this->getCoordinates().second);
        break;
    case (Direction::left):
        this->setCoordinates(this->getCoordinates().first - 1, this->getCoordinates().second);
        break;
    case (Direction::up):
        this->setCoordinates(this->getCoordinates().first, this->getCoordinates().second + 1);
        break;
    case (Direction::down):
        this->setCoordinates(this->getCoordinates().first + 1, this->getCoordinates().second - 1);
        break;
    }
}
#endif