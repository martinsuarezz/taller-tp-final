#include "Entity.h"
#include "../state/IdleState.h"
#include "../state/WalkingState.h"
#include "../World.h"

Entity::Entity(World& world, int x, int y) : world(world) {
  this->x = x;
  this->y = y;
  this->prevX = x;
  this->prevY = y;
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

char Entity::getType() const {
  return type;
}

bool Entity::isDynamic() const {
  return this->dynamic;
}

bool Entity:: isSolid() const {
  return this->solid;
}

int Entity::getVelocity() const{
  return this->velocity;
}

void Entity::setId(int id) {
  this->id = id;
}

void Entity::setPosition(int x, int y) {
  this->prevX = this->x;
  this->prevY = this->y;
  this->x = x;
  this->y = y;
}

std::vector<Event> &Entity::getEvents() {
  return events;
}

bool Entity::canMove(int x, int y) {
  return world.canMove(x, y);
}

