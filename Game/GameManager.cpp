#include "GameManager.h"
#include <set>
#include <iostream>
void GameManager::chooseLevel(int level){
    this->level = level;
}
bool GameManager::startLevel(){
    switch (level)
    {
    case 1:
        start_level_1();
        break;
    case 2:
        start_level_2();
        break;
    default:
        return false;
    }
    return true;
}
void GameManager::start_level_1(){
    Player player;
    Field field = FieldCreator().createFieldForLevel(1);
    MovementManager playerContol(player,field);
    controller(playerContol);

}

void GameManager::start_level_2(){
    Player player;
    Field field = FieldCreator().createFieldForLevel(2);
    MovementManager playerContol(player,field);
    controller(playerContol);
    
}
void GameManager::startGame(){
    std::cout << "Вы начали игру!";
    std::cout << "Введите уровень с которого хотите начать игру!";
    std::string level;
    while (true){
        
        std::cin >> level;
        try{
            chooseLevel(std::stoi(level));
        }
        catch(std::invalid_argument){
            chooseLevel(0);
        }
        if (!startLevel()){
            std::cout << "Вы ввели некорректный уровень! Попробуйте заново!";
        }
    }
}
bool GameManager::isLose(MovementManager& playerControl){
    return playerControl.getPlayer().isDead();
}
bool GameManager::isWin(MovementManager& playerControl){
    return playerControl.getCoordinates() == playerControl.getField().getFinish();
}
void GameManager::endLevel(bool win){
    if (win){
        std::cout << "Поздравляю, Вы прошли уровень!" << '\n';
    }
    else{
        std::cout << "Поздравляю, Вы мертвы! Теперь вы призрак!" << '\n';
    }
    char quit;
    std::cout << "Введите q, если хотите заверишть игру! Если введешь что-то другое игра начнется снова....Хахахаахаха\n";
    std::cin >> quit;
    if (quit == 'q'){
        exit(0);
    }
    std::cout << "Введите уровень с которого хотите начать игру!";
}
void GameManager::controller(MovementManager& playerControl){
    char dir;
    bool win;
    
    Input input;
    std::map<std::string, char> dictionary = input.read_dictionary("input.txt");
    if (dictionary.size() == 0) {
        throw(std::invalid_argument("Команды в файле указаны некорректно"));
    }
    playerControl.FieldView();
    while (dir != dictionary["quit"]) {
        dir = input._getch();
        if (dir == dictionary["up"]){
                playerControl.move(Direction::up);
                playerControl.FieldView();
        }
        if (dir == dictionary["down"]){
                playerControl.move(Direction::down);
                
                playerControl.FieldView();
        }
        if (dir == dictionary["left"]){
                playerControl.move(Direction::left);
                playerControl.FieldView();
        }
        if (dir == dictionary["right"]){
                playerControl.move(Direction::right);
                playerControl.FieldView();
        }
        if (isLose(playerControl)){
            win = false;
            break;
        }
        if (isWin(playerControl)){
            win = true;
            break;
        }
    }
    endLevel(win);
}