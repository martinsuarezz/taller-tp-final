#include "Creature.h"

Creature::Creature(World& world) : Character(world) {
  this->type = CREATURE;
}

void Creature::moveToward(Entity *entity) {
  srand(time(0));
  if (rand() % 2 == 0) {
    if (this->getX() - entity->getX() < 0) {
      this->move(x + 1, y);
    } else {
      this->move(x - 1, y);
    }
  } else {
    if (this->getY() - entity->getY() < 0) {
      this->move(x, y + 1);
    } else {
      this->move(x, y - 1);
    }
  }
}

void Creature::react(int event, Entity *sender) {
  switch(event) {
    case 0: // MOVE
      if(sender->getType() == PLAYER) {
        reactMove(sender);
      }
      break;
    case 1: // ATTACK
      break;
  }
}

void Creature::reactMove(Entity *sender) {
  if (this->isNearFrom((Character*) sender)) {
    this->moveToward(sender);
  } else if (this->isNextTo((Character*) sender)) {
    //TODO: Combat mode
  }
}