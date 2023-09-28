#include "MovementManager.h"
#include "Player.h"


MovementManager::MovementManager(Player& playerLink):playerLink (playerLink){};


void MovementManager::move(Direction direction)
{
            switch ((direction))
            {
                case (Direction::right):
                    this->playerLink.setCoordinates(playerLink.getCoordinates().first + 1, playerLink.getCoordinates().second);
                    break;
                case (Direction::left):
                    this->playerLink.setCoordinates(playerLink.getCoordinates().first - 1, playerLink.getCoordinates().second);
                    break;
                case (Direction::up):
                    this->playerLink.setCoordinates(playerLink.getCoordinates().first, playerLink.getCoordinates().second + 1);
                    break;
                case (Direction::down):
                    this->playerLink.setCoordinates(playerLink.getCoordinates().first + 1, playerLink.getCoordinates().second - 1);
                    break;
            }
}