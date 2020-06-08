#include "Creature.h"

Creature::Creature() : Character() {

}

void Creature::moveTo(Player* player) {
  if(this->getX() - player->getX() < 0) {
    x++;
  } else {
    x--;
  }

  if(this->getY() - player->getY() < 0) {
    y++;
  } else {
    y--;
  }
}
