#ifndef Cell_h
#define Cell_h
#include <iostream>
#include "../Events/Event.h"
class Field;
class Event;
class FieldCreator;
class Cell
{
    
    private:
        friend FieldCreator;
        bool cellPatency;
        Event* eve;
    public:
        Cell (Event* event = nullptr, bool cellPatency = true);
        Cell (const Cell& other);
        Cell (Cell&& other);
        ~Cell();
        void setCellPatency (bool cellPatency);
        bool getCellPatency () const;
        Event* getEve();
        Cell& operator=(const Cell& other);
        Cell& operator=(Cell &&other);
};  

#endif