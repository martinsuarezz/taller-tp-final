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

int Entity::getPrevX() const {
  return this->prevX;
}

int Entity::getPrevY() const {
  return this->prevY;
}

void Entity::setPosition(int x, int y) {
  this->prevX = this->x;
  this->prevY = this->y;
  this->x = x;
  this->y = y;
}

char Entity::getType() {
  return type;
}
