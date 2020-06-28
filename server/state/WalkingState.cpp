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
  }
}

void WalkingState::move(float inc) {
  if (action == MOVE_LEFT) {
    this->moveLeft(inc);
  } else if (action == MOVE_RIGHT) {
    this->moveRight(inc);
  } else if (action == MOVE_UP) {
    this->moveUp(inc);
  } else if (action == MOVE_DOWN) {
    this->moveDown(inc);
  } else {
    entity->setState(new IdleState(entity));
  }
}

void WalkingState::moveLeft(float inc) {
  if((this->x - inc) > entity->getX()) {
    this->x -= inc;
  } else {
    this->timeElapsed = 0;
    this->handleAction(action);
  }
}

void WalkingState::moveRight(float inc) {
  if((this->x + inc) < entity->getX()) {
    this->x += inc;
  } else {
    this->timeElapsed = 0;
    this->handleAction(action);
  }
}

void WalkingState::moveUp(float inc) {
  if((this->y - inc) > entity->getY()) {
    this->y -= inc;
  } else {
    this->timeElapsed = 0;
    this->handleAction(action);
  }
}

void WalkingState::moveDown(float inc) {
  if((this->y + inc) < entity->getY()) {
    this->y += inc;
  } else {
    this->timeElapsed = 0;
    this->handleAction(action);
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
