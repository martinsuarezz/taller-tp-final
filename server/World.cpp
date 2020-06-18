#include "World.h"
#include "entities/Creature.h"

World::World() {
  std::string filename("../map1.json");
  this->map = Map();
  map.load(filename);
}

Entity * World::getEntity(int id) {
  return dynamicEntities.find(id)->second;
}

void World::notify(Action action, Entity *sender) {
  // handle map
  map.notify(action, sender);

  // handle dynamic entities
  for(auto entity: dynamicEntities) {
    entity.second->react(action, sender);
  }

  if(action == DEAD) {
    this->deleteEntity(sender->getId());
  } else if(action == NEW_ENTITY) {
    this->addEntity(sender);
  }
}

std::string World::draw() const {
  return map.draw();
}

// Private methods

void World::addEntity(Entity *entity) {
  // Add to world
  if(entity->isDynamic()) {
    dynamicEntities.insert(std::make_pair(entity->getId(), entity));
  } else {
    staticEntities.insert(std::make_pair(entity->getId(), entity));
  }
}

void World::deleteEntity(int id) {
  dynamicEntities.erase(id);
}
