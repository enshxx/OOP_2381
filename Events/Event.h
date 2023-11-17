#ifndef Event_h
#define Event_h
class MovementManager;
class Event
{   
    public:
        virtual void start(MovementManager& controller) = 0;
        virtual Event* clone() const = 0;
        
};

#endif
