#include "Player.h"
#include "MovementManager.h"
#include "Inventory.h"

int main()
{
    Player player;
    MovementManager manager(player);
    manager.move(Direction::up);
    std::cout << player.getCoordinates().first << " " << player.getCoordinates().second << std::endl;
    player.inv->showInventory();

    return 0;
}

