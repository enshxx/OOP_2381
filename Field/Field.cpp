#include "Field.h"
#include "../Events/DefaultEvent.h"
Field::Field(int width, int height, std::pair<int,int> start, std::pair<int,int> finish)
{   
    this->width = (width - DEFAULT_WIDTH) * (width > 1 && width <= MAX_WIDTH) + DEFAULT_WIDTH;
    this->height = (height - DEFAULT_HEIGHT) * (height > 1 && height <= MAX_HEIGHT) + DEFAULT_HEIGHT;
    if (checkCoords(start, finish, width) && checkCoords(start, finish, height))
    {
        this->start = start;
        this->finish = finish;
    }
    else
    {
        this->start = std::make_pair(0,0);
        this->finish = std::make_pair(DEFAULT_WIDTH - 1, DEFAULT_HEIGHT - 1);
    }
    Cell **array;
    array = new Cell *[this->height];
    for (int i = 0; i < this->height; i++)
    {
        array[i] = new Cell[this->width];
        for (int j = 0; j < this->width; j++)
        {
            DefaultEvent* event = new DefaultEvent;
            array[i][j] = Cell(event, true);
        }
    }
    this->field = array;
}
Field::Field(Field& other) {
    width = other.width;
    height = other.height;
    start = other.start;
    finish = other.finish;

    field = new Cell*[height];
    for (int i = 0; i < height; ++i) {
        field[i] = new Cell[width];
    }

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            field[i][j] = other.field[i][j];
        }
    }
}
Field::Field (Field&& other)
    : width(other.width)
    , height(other.height)
    , start(std::move(other.start))
    , finish(std::move(other.finish))
    , field(other.field)
{
    other.field = nullptr;
}

Field::~Field()
{   
    if (this->field != nullptr)
    {
        for (int i = 0; i < height; i ++)
        {
            delete [] field[i];
        }
        delete [] field;
    }
}
int Field::checkCoords(std::pair<int,int> start, std::pair<int,int> finish, int value) const {return start.first >= 0 && start.first < value && start.second >= 0 && start.second < value; }
Cell &Field::getCell(int x, int y) { return this->field[x][y]; }
int Field::getWidth() const { return this->width; }
int Field::getHeight() const { return this->height; }

Field& Field::operator=(const Field& other){
    if (this == &other){
        return *this;
    }
    start = other.start;
    finish = other.finish;
    width = other.width;
    height = other.height;
    field = new Cell*[height];
    for (int i = 0; i < height; ++i) {
        field[i] = new Cell[width];
    }
    
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j){
            field[i][j] = other.field[i][j];
            }
        }
    return *this;
}
Field& Field::operator=(Field &&other){
    if (this == &other){
        return *this;
    }
    std::swap(start, other.start);
    std::swap(finish, other.finish);
    std::swap(width, other.width);
    std::swap(height, other.height);
    std::swap(field, other.field);
    return *this;
}

std::pair <int,int>  Field::getFinish()
{
    return this->finish;
}