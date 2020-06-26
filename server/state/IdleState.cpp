#include "IdleState.h"

void IdleState::update(Entity *entity, float dt) {
  if(x == 0 && y == 0) {
    this->x = entity->getX();
    this->y = entity->getY();
  }
}
