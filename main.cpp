#include "Player.h"
#include "MovementManager.h"
#include "Inventory.h"

int main()
{
    Player player;                   // cоздание экземпляра класса Player
    MovementManager manager(player); // создание экземпляра класса MovementManager

    // проверка ининциализации по умолчанию
    std::cout << "Здоровье игрока по умолчанию: " << player.getHealth() << std::endl;
    std::cout << "Cила игрока по умолчанию: " << player.getPower() << std::endl;
    std::cout << "Очки игрока по умолчанию " << player.getScore() << std::endl;
    std::cout << "Мертв ли игрок по умолчанию " << player.isDead() << std::endl;
    std::cout << "Координаты игрока по умолчанию " << manager.getCoordinates().first << " " << manager.getCoordinates().second << std::endl;
    std::cout << std::endl;

    // проверка изменения значений
    player.setHealth(player.getHealth() + 100);
    player.setPower(player.getPower() + 100);
    player.setScore(player.getScore() + 100);
    manager.move(Direction::right);

    // вывод после изменения
    std::cout << "Здоровье игрока поcле изменений: " << player.getHealth() << std::endl;
    std::cout << "Cила игрока после изменений: " << player.getPower() << std::endl;
    std::cout << "Очки игрока после изменений " << player.getScore() << std::endl;
    std::cout << "Мертв ли игрок после изменений " << player.isDead() << std::endl;
    std::cout << "Координаты игрока послеизменений " << manager.getCoordinates().first << " " << manager.getCoordinates().second << std::endl;
    std::cout << std::endl;

    // инвентарь по умолчанию

    // изменение количества предметов
    player.inv->flask->setCount(player.inv->flask->getCount() + 1);
    player.inv->powerPotion->setCount(player.inv->powerPotion->getCount() + 1);

    // проверка количества предметов после изменения
    player.inv->showInventory();

    // использование предметов
    player.inv->flask->use(player);
    player.inv->powerPotion->use(player);
    // свиток телепортации пока в разработке

    // вывод измемененных параметров
    std::cout << "Здоровье игрока поcле использования предмета: " << player.getHealth() << std::endl;
    std::cout << "Cила игрока после использования предмета: " << player.getPower() << std::endl;
    return 0;
}
