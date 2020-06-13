#include "World.h"

World::World() {
  std::string filename("../map1.json");
  this->map = Map();
  map.load(filename);
}

Entity * World::getEntity(int id) {
  return dynamicEntities.find(id)->second;
}

void World::addEntity(int x, int y, Entity *entity) {
  // Add to Map
  map.add(x, y, entity);

  // Add to world
  if(entity->isDynamic()) {
    dynamicEntities.insert(std::make_pair(entity->getId(), entity));
  } else {
    staticEntities.insert(std::make_pair(entity->getId(), entity));
  }
}

// TODO: Use Entity matrix to check
bool World::canMove(int x, int y) const {
  return map.isEmpty(x, y) && map.isInbound(x, y);
}

void World::notify(Event event, Entity *sender) {
  // notify map
  map.update(event, sender);

  // notify dynamic entities
  for(auto entity: dynamicEntities) {
    entity.second->react(event, sender);
  }
}

std::string World::draw() const {
  return map.draw();
}
