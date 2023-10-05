#include "Field.h"
#ifdef Field_h
#define Field_h
Field::Field(int width, int height, std::pair<int,int> start, std::pair<int,int> finish)
{   
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
    this->width = (width - DEFAULT_WIDTH) * (width > 1 && width <= MAX_WIDTH) + DEFAULT_WIDTH;
    this->height = (height - DEFAULT_HEIGHT) * (height > 1 && height <= MAX_HEIGHT) + DEFAULT_HEIGHT;
    Cell **array;
    array = new Cell *[this->height];
    for (int i = 0; i < this->height; i++)
    {
        array[i] = new Cell[this->width];
        for (int j = 0; j < this->width; j++)
        {
            array[i][j] = Cell(true, std::make_pair(i, j));
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
void Field::showField() const
{
    for (int i = 0; i < this->getHeight(); i++)
    {
        for (int j = 0; j < this->getWidth(); j++)
        {
            std::cout << this->field[i][j].coordinates.first << this->field[i][j].coordinates.second << " ";
        }
        std::cout << "\n";
    }
};
#endif