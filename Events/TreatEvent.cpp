#include "TreatEvent.h"
#include "../Player.h"
#include "../MovementManager.h"
TreatEvent::TreatEvent(int heal)
{
    this->heal = heal;
}

void TreatEvent::start(MovementManager& controller)
{
    Player& player = controller.getPlayer();
    player.setHealth(player.getHealth() + this->heal);
}
TreatEvent* TreatEvent::clone() const{
    return new TreatEvent(*this);
}