#include <iostream>
#include "Character.h"
#include "../World.h"
#include "Item.h"
#include "../state/WalkingState.h"
#include "../state/IdleState.h"

Character::Character(World &world, int x, int y) : world(world), Entity(x, y) {
  this->alive = true;
  this->health = 100;
  this->dynamic = true;
  this->solid = true;
  this->velocity = 1;
  this->state = new IdleState(this);
}

bool Character::isNearFrom(Character *character) {
  int distX = abs(character->getX() - this->getX());
  int distY = abs(character->getY() - this->getY());
  return distX <= 3 && distY <= 3;
}

bool Character::isNextTo(Character *character) {
  int distX = abs(character->getX() - this->getX());
  int distY = abs(character->getY() - this->getY());
  return distX <= 100 && distY <= 100;
}

void Character::moveRight() {
  this->setState(new WalkingState(this, MOVE_RIGHT));
  this->setPosition(this->x + 100, this->y);
  world.notify(MOVE, this);
}

void Character::moveLeft() {
  this->setState(new WalkingState(this, MOVE_LEFT));
  this->setPosition(this->x - 100, this->y);
  world.notify(MOVE, this);
}

void Character::moveUp() {
  this->setState(new WalkingState(this, MOVE_UP));
  this->setPosition(this->x, this->y - 100);
  world.notify(MOVE, this);
}

void Character::moveDown(){
  this->setState(new WalkingState(this, MOVE_DOWN));
  this->setPosition(this->x, this->y + 100);
  world.notify(MOVE, this);
}

void Character::update(float dt) {
  this->state->update(dt);
  // TODO: Notify Clients
  std::cout << this->state->getX() << " / " << this->state->getY() << std::endl;
}

void Character::attack(Character *enemy) {
  if (isNextTo(enemy)) {
    enemy->receiveDamage(10);
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
  Item* item = new Item(this->x, this->y);
  world.notify(NEW_ENTITY, item);
}

bool Character::isAlive() {
  return alive;
}

int Character::getHealth() {
  return health;
}
