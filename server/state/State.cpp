#include "State.h"

State::State(Entity *entity) : entity(entity) {
  this->timeElapsed = 0;
  this->inProgress = true;
  this->x = 0;
  this->y = 0;
  this->type = 0;
}

int State::getX() {
  return this->x;
}

int State::getY() {
  return this->y;
}

char State::getType() {
  return this->type;
}


