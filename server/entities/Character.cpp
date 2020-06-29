#include <iostream>
#include "Character.h"
#include "../World.h"
#include "Item.h"
#include "../state/IdleState.h"
#include "../state/WalkingState.h"

Character::Character(World &world, int x, int y) : Entity(world, x, y) {
  this->alive = true;
  this->health = 100;
  this->dynamic = true;
  this->solid = true;
  this->velocity = 3;
  this->state = new IdleState(this);
}

bool Character::isNearFrom(Character *character) {
  int distX = abs(character->getX() - this->getX());
  int distY = abs(character->getY() - this->getY());
  return distX <= config.getValue("max_near_from_distance")
    & distY <= config.getValue("max_near_from_distance");
}

bool Character::isNextTo(Character *character) {
  int distX = abs(character->getX() - this->getX());
  int distY = abs(character->getY() - this->getY());
  return distX <= 100 && distY <= 100;
}

void Character::setState(State *state) {
  this->state = state;
}

void Character::moveRight() {
  int nextX = this->x + 100;
  int nextY = this->y;

  if(this->canMove(nextX, nextY)) {
    this->setState(new WalkingState(this, MOVE_RIGHT));
    this->setPosition(nextX, nextY);
    world.notify(MOVE, this);
  }
}

void Character::moveLeft() {
  int nextX = this->x - 100;
  int nextY = this->y;

  if(this->canMove(nextX, nextY)) {
    this->setState(new WalkingState(this, MOVE_LEFT));
    this->setPosition(nextX, nextY);
    world.notify(MOVE, this);
  }
}

void Character::moveUp() {
  int nextX = this->x;
  int nextY = this->y - 100;

  if(this->canMove(nextX, nextY)) {
    this->setState(new WalkingState(this, MOVE_UP));
    this->setPosition(nextX, nextY);
    world.notify(MOVE, this);
  }
}

void Character::moveDown(){
  int nextX = this->x;
  int nextY = this->y + 100;

  if(this->canMove(nextX, nextY)) {
    this->setState(new WalkingState(this, MOVE_DOWN));
    this->setPosition(nextX, nextY);
    world.notify(MOVE, this);
  }
}

void Character::update(float dt) {
  this->state->update(dt);
  // TODO: Notify Clients
  std::cout << "Modelo: " << this->x << ":" << this->y << " / "
    << "Estado: " << this->state->getX() << ":" << this->state->getY()
    << " / " << "Tipo: " << this->state->getType() << std::endl ;
}

void Character::attack(Character *enemy) {
  if (isNextTo(enemy)) {
    enemy->receiveDamage(1);
    world.notify(ATTACK, this);
  }
}

void Character::receiveDamage(int damage) {
  int newHealth = health - damage;
  if (newHealth <= 0) {
    this->health = 0;
    this->alive = false;
    world.notify(DIE, this);
    dropItem();
  } else {
    this->health = newHealth;
    world.notify(RECEIVE_DAMAGE, this);
  }
}

void Character::dropItem() {
  Item* item = new Item(world, this->x, this->y);
  world.notify(NEW_ENTITY, item);
}

bool Character::isAlive() {
  return alive;
}

int Character::getHealth() {
  return health;
}
