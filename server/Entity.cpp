#include "Entity.h"

Entity::Entity() {
  this->x = 0;
  this->y = 0;
}

int Entity::getId() const {
  return this->id;
}

int Entity::getX() const {
  return this->x;
}

int Entity::getY() const {
  return this->y;
}

void Entity::setPosition(int x, int y) {
  this->x = x;
  this->y = y;
}

int Entity::getType() {
  return type;
}
