#include "IdleState.h"

IdleState::IdleState(Entity *entity) : State(entity) {
  this->type = 'I';
}

void IdleState::update(float dt) {

}
