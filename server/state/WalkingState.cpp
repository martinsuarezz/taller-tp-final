#include "WalkingState.h"
#include "IdleState.h"

WalkingState::WalkingState(Entity* entity, Action action) : State(entity) {
  this->x = entity->getX();
  this->y = entity->getY();
  this->action = action;
  this->entity = entity;
  this->type = 'W';
}

void WalkingState::update(float dt) {
  float inc = entity->getVelocity() * dt * 100;

  this->timeElapsed += dt;

  if (action == MOVE_LEFT) {
    this->x -= inc;
  } else if (action == MOVE_RIGHT) {
    this->x += inc;
  } else if (action == MOVE_UP) {
    this->y += inc;
  } else if (action == MOVE_DOWN) {
    this->y -= inc;
  }

  if (timeElapsed >= 1) {
    this->x = entity->getX();
    this->y = entity->getY();

    if (inProgress) {
      this->timeElapsed = 0;
    } else {
      entity->setState(new IdleState(entity));
    }
  }
}

