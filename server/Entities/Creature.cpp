#include <sstream>
#include "Creature.h"
#include "Item.h"

Creature::Creature(World& world, int id) : Character(world) {
  this->id = id;
  this->health = 50;
  this->type = CREATURE;
  this->alive = true;
}

void Creature::react(Event event, Entity *sender) {
    switch (event) {
      case MOVE:
        if(sender->getType() == PLAYER) reactMove(sender);
        break;
      case DEAD:break;
      case ATTACK:break;
      case RECEIVE_DAMAGE:break;
      case NEW_ENTITY: break;
    }
}

// Private methods

void Creature::moveToward(Entity *entity) {
  srand(time(nullptr));
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