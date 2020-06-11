#include "Character.h"
#include "World.h"

Character::Character(World &map) : map(map), Entity() {
  map.addEntity(this, 0, 0);
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
  if(!map.isEmpty(nextX, nextY) && map.isInbound(nextX, nextY)) {
    map.moveTo(nextX, nextY, this);
    this->setPosition(nextX, nextY);
    this->notify();
  }
}

void Character::notify() {
//  for(auto entity: ) {
//    if (creature->isNextTo(player)) {
//      // TODO: Combat mode
//    } else if (creature->isNearFrom(player)) {
//      int actualX = creature->getX();
//      int actualY = creature->getY();
//      if(world.isInbound(actualX, actualY)) {
//        creature->moveTo(player);
//        //world.moveTo(create->get,);
//      }
//    }
//  }
}
