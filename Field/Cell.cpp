#include "Cell.h"
#ifndef Cell_cpp
#define Cell_cpp

Cell::Cell(bool cellPatency, std::pair<int, int> coordinates)
{
    this->cellPatency = cellPatency;
    this->coordinates = coordinates;
}
void Cell::setCellPatency(bool cellPatency) { this->cellPatency = cellPatency; }
bool Cell::getCellPatency() { return this->cellPatency; }
void Cell::operator=(Cell other) {}
#endif