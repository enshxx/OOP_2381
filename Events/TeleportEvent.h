#ifndef TeleportEvent_h
#define TeleportEvent_h
#include "Event.h"
#include <iostream>
class TeleportEvent: public Event{
    std::pair<int,int> coord;
    public:
        TeleportEvent(std::pair<int,int> coord);
        TeleportEvent* clone() const override;
        void start(MovementManager& controller) override;
};

#endif