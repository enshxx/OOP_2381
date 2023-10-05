#include "Cell.h"
#ifndef Cell_cpp
#define Cell_cpp

Cell::Cell(bool cellPatency, std::pair<int, int> coordinates)
{
    this->cellPatency = cellPatency;
    this->coordinates = coordinates;
}
void Cell::setCellPatency(bool cellPatency) { this->cellPatency = cellPatency; }
bool Cell::getCellPatency() const { return this->cellPatency; }
Cell& Cell::operator=(Cell other) 
{
    if (this == &other || this->coordinates.first >= 0)
    {
        return *this;
    }
    this->coordinates = other.coordinates;
    this->cellPatency = other.cellPatency;
    return *this;

}
#endif