#include "WalkingState.h"
#include "IdleState.h"

WalkingState::WalkingState(Character* character, Action action) : State(character) {
  this->character = character;
  this->action = action;
  this->type = 'W';
  this->x = character->getX();
  this->y = character->getY();
}

void WalkingState::update(float dt) {
  this->timeElapsed += dt;
  float inc = character->getVelocity() * dt * 100;

  // Couldn't move
  if(character->getX() == character->getPrevX() && character->getY() == character->getPrevY()) {
    character->setState(new IdleState(character));
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
    character->setState(new IdleState(character));
  }
}

void WalkingState::moveLeft(float inc) {
  if((this->x - inc) >= character->getX()) {
    this->x -= inc;
  } else {
    this->timeElapsed = 0;
    this->handleAction(action);
  }
}

void WalkingState::moveRight(float inc) {
  if((this->x + inc) <= character->getX()) {
    this->x += inc;
  } else {
    this->timeElapsed = 0;
    this->handleAction(action);
  }
}

void WalkingState::moveUp(float inc) {
  if((this->y - inc) >= character->getY()) {
    this->y -= inc;
  } else {
    this->timeElapsed = 0;
    this->handleAction(action);
  }
}

void WalkingState::moveDown(float inc) {
  if((this->y + inc) <= character->getY()) {
    this->y += inc;
  } else {
    this->timeElapsed = 0;
    this->handleAction(action);
  }
}

void WalkingState::handleAction(Action action) {
  if (action == MOVE_LEFT) {
    character->moveLeft();
  } else if (action == MOVE_RIGHT) {
    character->moveRight();
  } else if (action == MOVE_UP) {
    character->moveUp();
  } else if (action == MOVE_DOWN) {
    character->moveDown();
  }
}
