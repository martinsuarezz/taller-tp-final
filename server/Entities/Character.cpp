#include "Character.h"
#include "../World.h"

Character::Character(World &world) : world(world), Entity() {
  this->dynamic = true;
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

void Character::move(int nextX, int nextY) {
  if(world.canMove(nextX, nextY)) {
    this->setPosition(nextX, nextY);
    world.notify(MOVE, this);
  }
}

void Character::attack(Character* enemy) {
  if(isNextTo(enemy)) {
    enemy->receiveDamage(10);
    world.notify(ATTACK, this);
  }
}

void Character::receiveDamage(int damage) {
  int newHealth = health - damage;
  if (newHealth <= 0) {
    this->alive = false;
    world.notify(DEAD, this);
  } else {
    this->health = newHealth;
    world.notify(RECEIVE_DAMAGE, this);
  }
}

bool Character::isAlive() {
  return alive;
}

int Character::getHealth() {
  return health;
}