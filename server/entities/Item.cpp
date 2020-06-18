#include "Item.h"
#include "../World.h"

Item::Item() {
  this->dynamic = true;
  this->solid = false;
  this->type = ITEM;
}

void Item::react(Action action, Entity *sender) {
  // Do nothing
}
