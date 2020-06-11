#include "Character.h"
#include "../World.h"

Character::Character(World &world) : world(world), Entity() {
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
    world.notify(0, this);
  }
}
