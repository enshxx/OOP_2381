#ifndef Field_h
#define Field_h
#define DEFAULT_WIDTH 30
#define DEFAULT_HEIGHT 30
#define MAX_WIDTH 200
#define MAX_HEIGHT 200
#include <iostream>
#include "Cell.h"

class Field{
    private:
        int width, height;
        std::pair <int,int> start,finish;
        Cell** field;
    public:
        Field(int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT, std::pair<int,int> start = std::make_pair(0,0), std::pair<int,int> finish = std::make_pair(DEFAULT_WIDTH - 1,DEFAULT_HEIGHT - 1));
        Field (Field& other);
        Field (Field&& other);
        ~Field();
        Cell& getCell(int x, int y);
        int checkCoords(std::pair<int,int> start,std::pair<int,int> finish ,int value) const;
        int getWidth() const;
        int getHeight() const;
        void showField() const;
};
#endif