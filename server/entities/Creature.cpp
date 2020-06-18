#include <sstream>
#include "Creature.h"
#include "Item.h"

Creature::Creature(World& world, int id) : Character(world) {
  this->id = id;
  this->health = 50;
  this->type = CREATURE;
  this->alive = true;
}

void Creature::react(Action action, Entity *sender) {
    if((action == MOVE_LEFT ||  action == MOVE_RIGHT || action == MOVE_UP
      || action == MOVE_DOWN) && sender->getType() == PLAYER) {
        reactMove(sender);
    }
}

// Private methods

void Creature::moveToward(Entity *entity) {
  srand(time(nullptr));
  if (rand() % 2 == 0) {
    if (this->getX() - entity->getX() < 0) {
      this->moveRight();
    } else {
      this->moveLeft();
    }
  } else {
    if (this->getY() - entity->getY() < 0) {
      this->moveUp();
    } else {
      this->moveDown();
    }
  }
}

void Creature::reactMove(Entity *sender) {
  Character* target = dynamic_cast<Character *>(sender);

  if (this->isNearFrom(target)) {
    this->moveToward(target);
  } else if (this->isNextTo(target)) {
    this->attack(target);
  }
}

std::string Creature::toString() const {
  std::stringstream ss;

  ss << "Id: " << this->id << " - "
     << "Vida: " << this->health;

  return ss.str();
}