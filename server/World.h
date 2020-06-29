#ifndef ARGENTUM__MAP_H_
#define ARGENTUM__MAP_H_

#include <string>
#include <vector>
#include <map>

#include "Command.h"
#include "Map.h"
#include "EventManager.h"

class World {
 public:
  World();

  Entity * getEntity(int id);

  void notify(Event event, Entity *sender);

  bool canMove(int x, int y);

  // Just for testing:
  std::string draw() const;
  void update(float dt);

  std::map<int, Entity *>& getDynamicEntities();
 private:
  Map map;
  EventManager eventManager;

  std::map<int, Entity *> dynamicEntities;
  std::map<int, Entity *> staticEntities;

  void addEntity(Entity *entity);
  void deleteEntity(Entity *entity);
};

#endif