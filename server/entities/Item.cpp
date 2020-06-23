#include "Item.h"
#include "../World.h"

Item::Item() {
  this->dynamic = true;
  this->solid = false;
  this->type = ITEM;
}

void Item::react(Event event, Entity *sender) {
  // Do nothing
}
