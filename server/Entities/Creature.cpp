#include <sstream>
#include "Creature.h"

Creature::Creature(World& world, int id) : Character(world) {
  this->id = id;
  this->health = 50;
  this->type = CREATURE;
}

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

void Creature::react(Event event, Entity *sender) {
  if(this->alive && sender->getType() == PLAYER) {
    switch (event) {
      case MOVE:
        reactMove(sender);
        break;
      case ATTACK:break;
      case RECEIVE_DAMAGE:break;
      case DEAD:break;
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