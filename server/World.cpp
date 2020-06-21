#include "World.h"
#include "events/EventManager.h"

World::World() {
  std::string filename("../map1.json");
  this->map = Map();
  map.load(filename);
}

Entity * World::getEntity(int id) {
  return dynamicEntities.find(id)->second;
}

void World::notify(Event event, Entity *sender) {
  // handle map
  map.notify(event, sender);

  eventManager.notify(event, sender);

  if(event == DIE) {
    // FIXME: If it's a player should transform
    this->deleteEntity(sender->getId());
  } else if(event == NEW_ENTITY) {
    this->addEntity(sender);
  } else if(event == REMOVE_ENTITY){
    this->deleteEntity(sender->getId());
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

    for(auto event : entity->getEvents()) {
      eventManager.subscribe(event, entity);
    }
  } else {
    staticEntities.insert(std::make_pair(entity->getId(), entity));
  }
}

void World::deleteEntity(int id) {
  dynamicEntities.erase(id);
  // TODO: Unsubscribe events
  // TODO: Remove pointer
}
