#ifndef ARGENTUM__MAP_H_
#define ARGENTUM__MAP_H_

#include <string>
#include <vector>
#include <map>

#include "Entities/Entity.h"
#include "Event.h"
#include "Map.h"

#define EMPTY ' '
#define TREE 'T'
#define PLAYER 'P'
#define CREATURE 'C'
#define ITEM '*'

class World {
 public:
  World();

  Entity * getEntity(int id);

  void notify(Event event, Entity *sender);

  // Just for testing:
  std::string draw() const;
 private:
  Map map;

  std::map<int, Entity *> dynamicEntities;
  std::map<int, Entity *> staticEntities;

  void addEntity(Entity *entity);
  void deleteEntity(int id);
};

#endif