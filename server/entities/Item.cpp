#include "Item.h"
#include "../World.h"

Item::Item(World& world, int x, int y) : Entity(world, x,y) {
  this->dynamic = false;
  this->solid = false;
  this->type = '*';
}

void Item::react(Event event, Entity *sender) {
  // Do nothing
}

void Item::update(float dt) {

}
