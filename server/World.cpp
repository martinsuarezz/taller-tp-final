#include "World.h"

World::World() {
  std::string filename("../map1.json");
  this->map = Map();
  map.load(filename);
}

Entity * World::getEntity(int id) {
  return dynamicEntities.find(id)->second;
}

void World::notify(Event event, Entity *sender) {
  // notify map
  map.notify(event, sender);

  // notify dynamic entities
  for(auto entity: dynamicEntities) {
    entity.second->react(event, sender);
  }

  switch(event) {
    case DEAD:
      this->deleteEntity(sender->getId());
      break;
    case NEW_ENTITY:
      this->addEntity(sender);
      break;
    case MOVE:break;
    case ATTACK:break;
    case RECEIVE_DAMAGE:break;
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
