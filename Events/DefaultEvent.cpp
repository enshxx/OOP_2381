#ifndef DefaultEvent_cpp
#define DefaultEvent_cpp
#include "../MovementManager.h"
#include "DefaultEvent.h"
#include "../Player.h"
#define STEP 1
void DefaultEvent::start(MovementManager& controller)
{
    Player& player =  controller.getPlayer();
    player.setScore(player.getScore() + STEP);
}
DefaultEvent* DefaultEvent::clone() const{
    return new DefaultEvent(*this);
}
#endif