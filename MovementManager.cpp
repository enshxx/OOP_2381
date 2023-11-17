#include "MovementManager.h"
#include "Player.h"
#ifndef MovementManager_cpp
#define MovementManager_cpp

MovementManager::MovementManager(Player &playerLink, Field &field, int x, int y) : playerLink(playerLink), field(field)
{
    this->setCoordinates(x, y);
};

std::pair<int, int> MovementManager::getCoordinates() const{ return this->coordinates; }
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
        new_y--;
        break;
    case (Direction::down):
        new_y++;
        break;
    }

    if (check(new_x, new_y))
        this->setCoordinates(new_x, new_y);
        this->field.getCell(new_x,new_y).getEve()->start(*this);
}
Player& MovementManager::getPlayer()
{
    return this->playerLink;
}
void MovementManager::operator=(MovementManager other){};
void MovementManager::teleport(std::pair<int,int> coordinate){
    int x = coordinate.first;
    int y = coordinate.second;
    int coordX = this->coordinates.first;
    int coordY = this->coordinates.first;
    if ((this->check(coordX, coordY) && this->field.getCell(coordX, coordY).getCellPatency())){
    }
        
        this->coordinates.first = x;
        this->coordinates.second = y;
        field.getCell(y,x).getEve()->start(*this);
        
}
Field& MovementManager::getField()
{
    return this->field;
}
void MovementManager::FieldView() {
    int w = field.getWidth();
    int h = field.getHeight();
    int x_start = 0;
    int y_start = 0;
    int x_end = 0;
    int y_end = 0;
    if (w <= 10 && h <= 10) {
        x_start = 0;
        y_start = 0;
        x_end = w;
        y_end = h;
    } else {
        int x_center = this->coordinates.first;
        int y_center = this->coordinates.second;
        
        if (x_center < 3) { x_start = 0; x_end = 7; }
        else if (x_center >= w-3) { x_start = w-7; x_end = w; }
        else { x_start = x_center - 3; x_end = x_center + 4; }

        if (y_center < 3) { y_start = 0; y_end = 7; }
        else if (y_center >= h-3) { y_start = h-7; y_end = h; }
        else { y_start = y_center - 3; y_end = y_center + 4; }
    }
    int x = this->coordinates.first;
    int y = this->coordinates.second;
    std::cout << "--------------\n";
    for (int i = y_start; i < y_end; i++) {
        for (int j = x_start; j < x_end; j++) {
            if (field.getCell(j, i).getCellPatency()) {
                if (x == j && y == i)
                    if (playerLink.isDead()){
                        std::cout << "(X-X)";
                    }
                    else{
                        std::cout << "(T-T)";
                    }
                else
                    std::cout << "  .  ";
            } else {
                std::cout << " [#] ";
            }
        }
        std::cout << "\n";
    }
}
#endif