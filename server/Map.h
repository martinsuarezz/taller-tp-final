#ifndef ARGENTUM_SERVER_MAP_H_
#define ARGENTUM_SERVER_MAP_H_

#include <string>
#include "entities/Entity.h"

class Map {
 public:

  void load(std::string &filename);

  bool canMove(int x, int y) const;

  void notify(Event event, Entity *entity);

  // Just for testing
  std::string draw() const;
 private:
  int height;
  int width;

  Entity** map;

  bool isEmpty(int x, int y) const;
  bool isInbound(int x, int y) const;

  Entity *get(int x, int y) const;
  void set(int x, int y, Entity *entity);
  void move(Entity * entity);
  void remove(Entity *entity);
  void add(Entity *entity);
};

#endif