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

class World {
 public:
  World();

  Entity * getEntity(int id);

  void addEntity(int x, int y, Entity *entity);

  void updateMap(Entity *entity);

  bool canMove(int x, int y) const;

  void notify(Event event, Entity *sender);

  // Just for testing:
  std::string draw() const;
 private:
  Map map;
  std::map<int, Entity *> staticEntities;
  std::map<int, Entity *> dynamicEntities;
};

#endif