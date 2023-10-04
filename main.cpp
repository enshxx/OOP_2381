#include "Field/Field.h"
#include "Player.h"
#include "Inventory.h"
#include "MovementManager.h"
int main()
{  
    Field field;
    Player player;                   // cоздание экземпляра класса Player
    MovementManager manager(player,field); // создание экземпляра класса MovementManager

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

    // вывод после изменения
    std::cout << "Здоровье игрока поcле изменений: " << player.getHealth() << std::endl;
    std::cout << "Cила игрока после изменений: " << player.getPower() << std::endl;
    std::cout << "Очки игрока после изменений " << player.getScore() << std::endl;
    std::cout << "Мертв ли игрок после изменений " << player.isDead() << std::endl;
    std::cout << "Координаты игрока послеизменений " << manager.getCoordinates().first << " " << manager.getCoordinates().second << std::endl;
    std::cout << std::endl;

    // инвентарь по умолчанию
    player.getInventory().showInventory();

    // изменение количества предметов
    player.getInventory().getFlask().setCount(player.getInventory().getFlask().getCount() + 1);
    player.getInventory().getPowerPotion().setCount(player.getInventory().getFlask().getCount() + 1);

    // проверка количества предметов после изменения
    player.getInventory().getFlask().use(player);
    player.getInventory().getPowerPotion().use(player);


    // вывод измемененных параметров
    std::cout << "Здоровье игрока поcле использования предмета: " << player.getHealth() << std::endl;
    std::cout << "Cила игрока после использования предмета: " << player.getPower() << std::endl;

    //Проверека движения
    manager.move(Direction::right);
    std::cout << manager.getCoordinates().first << " " << manager.getCoordinates().second << std::endl;
    std::cout << std::endl;

    //Проверка на присвоение
    std::cout << (field.getCell(1,1).getCellPatency()) << std::endl;
    Cell n = Cell(false);
    field.getCell(1,1) = n;
    std::cout << (field.getCell(1,1).getCellPatency()) << std::endl;

    //проверка конструктора копирования
    Field new_field = Field(field);
    
    Field new_field1(std::move(field));
    
    return 0;

}
