#include "Cell.h"
#ifndef Cell_cpp
#define Cell_cpp

Cell::Cell(Event* eve, bool cellPatency)
{
    this->eve = eve;
    this->cellPatency = cellPatency;
}
void Cell::setCellPatency(bool cellPatency) { this->cellPatency = cellPatency; }
bool Cell::getCellPatency() const { return this->cellPatency; }
Event* Cell::getEve(){
    return this->eve;
}
Cell::Cell(const Cell &other) : cellPatency{other.cellPatency},
      eve{other.eve ? other.eve->clone() : nullptr}{}


Cell::Cell(Cell&& other): eve(nullptr), cellPatency(true){
    std::swap(eve,other.eve);
    std::swap(cellPatency,other.cellPatency);
}
Cell::~Cell()
{
     if (this->eve != nullptr)
        {
        delete eve;
    }
}    
Cell& Cell::operator=(const Cell& other){
    if (this == &other)
    {
        return *this;
    }
    Cell tmp(other);
    std::swap(cellPatency, tmp.cellPatency);
    std::swap(eve, tmp.eve);
    return *this;
};
Cell& Cell::operator=(Cell &&other)
{
    if (this != &other) {
        std::swap(cellPatency, other.cellPatency);
        std::swap(eve, other.eve);        
    }
    return *this;
}
#endif