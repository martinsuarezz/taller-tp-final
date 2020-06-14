#include "Item.h"

Item::Item() {
  this->dynamic = true;
  this->solid = false;
}

void Item::react(Event event, Entity *sender) {
  // Do nothing
}
