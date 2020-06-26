#include "WalkingState.h"
#include "IdleState.h"

WalkingState::WalkingState(Action action) {
  this->action = action;
}

void WalkingState::update(Entity* entity, int dt) {
  int x = entity->getX();
  int y = entity->getY();
  int inc = entity->getVelocity() * dt * 100;

  this->timeElapsed += dt;

  if (action == MOVE_LEFT) {
    entity->setPosition(x - inc, y);
  } else if (action == MOVE_RIGHT) {
    entity->setPosition(x + inc, y);
  } else if (action == MOVE_UP) {
    entity->setPosition(x, y + inc);
  } else if (action == MOVE_DOWN) {
    entity->setPosition(x, y - inc);
  }

  if (timeElapsed >= 1) {
    if (inProgress) {
      this->timeElapsed = 0;
    } else {
      entity->setState(new IdleState());
    }
  }
}

