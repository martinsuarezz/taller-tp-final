#include "IdleState.h"

IdleState::IdleState(Entity *entity) : State(entity) {
  this->x = entity->getX();
  this->y = entity->getY();
  this->type = 'I';
}

void IdleState::update(float dt) {

}
