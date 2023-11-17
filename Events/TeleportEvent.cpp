#include "TeleportEvent.h"
#include "../Player.h"
#include "../MovementManager.h"
TeleportEvent::TeleportEvent(std::pair<int,int> coord):coord(coord){}

void TeleportEvent::start(MovementManager& controller){
    controller.teleport(this->coord);
}
TeleportEvent* TeleportEvent::clone() const{
    return new TeleportEvent(*this);
}