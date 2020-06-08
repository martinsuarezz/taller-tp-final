#include <complex>
#include "Character.h"

Character::Character() {
  this->x = 0;
  this->y = 0;
}

int Character::getId() const {
  return this->id;
}

int Character::getX() const {
  return this->x;
}

int Character::getY() const {
  return this->y;
}

void Character::setPosition(int x, int y) {
  this->x = x;
  this->y = y;
}

bool Character::isNearFrom(Character *character) {
  int distX = abs(character->getX() - this->getX());
  int distY = abs(character->getY() - this->getY());
  return distX <= 3 && distY <= 3;
}

bool Character::isNextTo(Character *character) {
  int distX = abs(character->getX() - this->getX());
  int distY = abs(character->getY() - this->getY());
  return distX <= 1 && distY <= 1;
}