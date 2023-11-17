#ifndef FieldCreator_h
#define FieldCreator_h
#include "Field.h"
class FieldCreator{
    private:
        Field createFieldForLevel1();
        Field createFieldForLevel2();
    public:
        FieldCreator();
        Field createFieldForLevel(int level);
};
#endif