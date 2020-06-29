#include "State.h"
#include "../entities/Character.h"

State::State(Character *character) : character(character) {
  this->timeElapsed = 0;
  this->inProgress = true;
  this->x = character->getX();
  this->y = character->getY();
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


