#include <iostream>
#ifndef Cell_h
#define Cell_h
class Cell
{
    private:
        bool cellPatency;
        std::pair<int,int> coordinates;
    public:
        Cell (bool cellPatency = true, std::pair<int,int> coordinates = std::make_pair(-1,-1));
        void setCellPatency (bool cellPatency);
        bool getCellPatency () const;
        void operator=(Cell other);
};  

#endif