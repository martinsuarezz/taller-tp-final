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
  this->timeElapsed += dt;
  float inc = entity->getVelocity() * dt * 100;

  // Couldn't move
  if(entity->getX() == entity->getPrevX() && entity->getY() == entity->getPrevY()) {
    entity->setState(new IdleState(entity));
  } else {
    this->move(inc);

    // Arrives at position
    if (this->x == entity->getX() && this->y == entity->getY()) {
      this->timeElapsed = 0;
      this->handleAction(action);
    }
  }
}

void WalkingState::move(float inc) {
  if (action == MOVE_LEFT && entity->canMove(x - inc, y)) {
    this->x -= inc;
  } else if (action == MOVE_RIGHT && entity->canMove(x + inc, y)) {
    this->x += inc;
  } else if (action == MOVE_UP && entity->canMove(x, y - inc)) {
    this->y -= inc;
  } else if (action == MOVE_DOWN && entity->canMove(x, y + inc)) {
    this->y += inc;
  } else {
    entity->setState(new IdleState(entity));
  }
}

void WalkingState::handleAction(Action action) {
  if (action == MOVE_LEFT) {
    entity->moveLeft();
  } else if (action == MOVE_RIGHT) {
    entity->moveRight();
  } else if (action == MOVE_UP) {
    entity->moveUp();
  } else if (action == MOVE_DOWN) {
    entity->moveDown();
  }
}
