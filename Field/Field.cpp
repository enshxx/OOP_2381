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
Field::~Field()
{
    for (int i = 0; i < height; i ++)
    {
        delete [] field[i];
    }
    delete [] field;
}

Cell &Field::getCell(int x, int y) { return this->field[x][y]; }
int Field::getWidth() { return this->width; }
int Field::getHeight() { return this->height; }
void Field::operator=(Field other){};
#endif