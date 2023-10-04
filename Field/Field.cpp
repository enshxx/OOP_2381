#include "Field.h"
#ifdef Field_h
#define Field_h
Field::Field(int width, int height)
{
    this->width = width;
    this->height = height;
    Cell **array;
    array = new Cell *[height];
    for (int i = 0; i < height; i++)
    {
        array[i] = new Cell[width];
        for (int j = 0; j < width; j++)
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

Cell &Field::getCell(int x, int y) { return this->field[x][y]; }
int Field::getWidth() const { return this->width; }
int Field::getHeight() const { return this->height; }
void Field::operator=(Field other){};
#endif