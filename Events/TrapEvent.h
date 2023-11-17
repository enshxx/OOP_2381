#ifndef TrapEvent_h
#define TrapEvent_h
#include "Event.h"
#define DEFAULT_DAMAGE 20
class TrapEvent: public Event
{
    private:
        int damage;
    public:
        TrapEvent* clone() const override;
        TrapEvent (int damage = DEFAULT_DAMAGE);
        void start(MovementManager& controller) override;
};
#endif