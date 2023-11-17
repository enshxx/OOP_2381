#ifndef DefaultEvent_h
#define DefaultEvent_h
#include "Event.h"
class DefaultEvent: public Event
{
    public:
        DefaultEvent* clone() const override;
        void start(MovementManager& controller) override;
};

#endif