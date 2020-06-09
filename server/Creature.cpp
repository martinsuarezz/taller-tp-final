#include "Creature.h"

Creature::Creature() : Character() {

}

void Creature::moveTo(Player* player) {
  srand(time(0));
  if (rand() % 2 == 0) {
    if (this->getX() - player->getX() < 0) {
      this->x++;
    } else {
      this->x--;
    }
  } else {
    if (this->getY() - player->getY() < 0) {
      this->y++;
    } else {
      this->y--;
    }
  }
}
