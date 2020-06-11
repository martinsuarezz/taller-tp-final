#include "Creature.h"

Creature::Creature(World& map) : Character(map) {
  this->type = CREATURE;
  map.addEntity(this, 0, 0);
}

void Creature::moveTo(Entity *entity) {
  srand(time(0));
  if (rand() % 2 == 0) {
    if (this->getX() - entity->getX() < 0) {
      this->x++;
    } else {
      this->x--;
    }
  } else {
    if (this->getY() - entity->getY() < 0) {
      this->y++;
    } else {
      this->y--;
    }
  }
}
