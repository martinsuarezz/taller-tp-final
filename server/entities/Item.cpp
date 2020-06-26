#include "Item.h"
#include "../World.h"

Item::Item(int x, int y) : Entity(x,y) {
  this->dynamic = true;
  this->solid = false;
  this->type = ITEM;
}

void Item::react(Event event, Entity *sender) {
  // Do nothing
}

void Item::update(float dt) {

}
