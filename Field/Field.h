#ifndef Field_h
#define Field_h
#define DEFAULT_WIDTH 100
#define DEFAULT_HEIGHT 100
#include <iostream>
#include "Cell.h"

class Field{
    private:
        int width, height;
        std::pair <int,int> start,finish;
        Cell** field;
    public:
        Field(int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT);
        Field (Field& other);
        Field (Field&& other);
        ~Field();
        Cell& getCell(int x, int y);
        int getWidth() const;
        int getHeight() const;
        void operator=(Field other);
};
#endif