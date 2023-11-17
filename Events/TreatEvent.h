#ifndef TreatEvent_h
#define TreatEvent_h
#include "Event.h"
#define DEFAULT_HEAL 50
class TreatEvent : public Event{
    int heal;
    public:
        TreatEvent* clone() const override;
        TreatEvent(int heal = DEFAULT_HEAL);
        void start(MovementManager& controller) override;
};

#endif