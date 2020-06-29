#include "IdleState.h"

IdleState::IdleState(Character *character) : State(character) {
  this->type = 'I';
}

void IdleState::update(float dt) {

}
