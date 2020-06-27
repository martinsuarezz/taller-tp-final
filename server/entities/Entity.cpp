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

void Entity::setState(State* state) {
  this->state = state;
}

void Entity::moveRight() {
  this->setState(new WalkingState(this, MOVE_RIGHT));
  this->setPosition(this->x + 100, this->y);
  world.notify(MOVE, this);
}

void Entity::moveLeft() {
  this->setState(new WalkingState(this, MOVE_LEFT));
  this->setPosition(this->x - 100, this->y);
  world.notify(MOVE, this);
}

void Entity::moveUp() {
  this->setState(new WalkingState(this, MOVE_UP));
  this->setPosition(this->x, this->y - 100);
  world.notify(MOVE, this);
}

void Entity::moveDown(){
  this->setState(new WalkingState(this, MOVE_DOWN));
  this->setPosition(this->x, this->y + 100);
  world.notify(MOVE, this);
}

bool Entity::canMove(int x, int y) {
  return world.canMove(x / 100, y / 100);
}

