#include "TrapEvent.h"
#include "../Player.h"
#include "../MovementManager.h"
TrapEvent::TrapEvent(int damage)
{
    this->damage = damage;
}

void TrapEvent::start(MovementManager& controller)
{
    Player& player = controller.getPlayer();
    player.setHealth(player.getHealth() - this->damage);
}

TrapEvent* TrapEvent::clone() const{
    return new TrapEvent(*this);
}