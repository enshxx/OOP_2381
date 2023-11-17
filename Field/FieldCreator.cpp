#include "FieldCreator.h"
#include "../Events/Event.h"
#include "../Events/DefaultEvent.h"
#include "../Events/TrapEvent.h"
#include "../Events/TreatEvent.h"
#include "../Events/TeleportEvent.h"

FieldCreator::FieldCreator() = default;
Field FieldCreator::createFieldForLevel(int level){
    switch (level)
    {
    case 1:
        return createFieldForLevel1();
        break;
    case 2:
        return createFieldForLevel2();
        break;
    default:
        throw std::invalid_argument("Несуществующий уровень");
    }
}
Field FieldCreator::createFieldForLevel1(){
    int height = 10;
    int width = 10;
    std::pair <int, int> start = std::make_pair(0,0);
    std::pair <int, int>  end = std::make_pair(height - 1, width - 1);
    Field new_field = Field(height,width,start,end);
    for (int i = 0; i < 10; i++){
        for (int j = i+2; j <10; j++){
            new_field.getCell(j,i).setCellPatency(false);
             new_field.getCell(i,j).setCellPatency(false);
        }
    }
    Event* tp = new TeleportEvent(std::make_pair(3,3));
    Event* trap = new TrapEvent(10000);
    Event* treat = new TreatEvent(10000);
    new_field.getCell(0,1).eve = new TeleportEvent(std::make_pair(3,3));
    new_field.getCell(3,4).eve = new TrapEvent();
    new_field.getCell(7,8).eve = new TreatEvent();
    return new_field;
}

Field FieldCreator::createFieldForLevel2(){
    int height = 10;
    int width = 10;
    std::pair<int,int> start = std::make_pair(0,0);
    std::pair<int,int> finish = std::make_pair(height - 1, width - 1);
    Field new_field = Field(height,width,start,finish);
    Event* trap = new TrapEvent(10000);
    Event* treat = new TreatEvent(10000);
    new_field.getCell(3,4).eve = trap;
    new_field.getCell(7,8).eve = treat;
    return new_field;
}