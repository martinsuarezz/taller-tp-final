#ifndef ARGENTUM_SERVER_MAP_H_
#define ARGENTUM_SERVER_MAP_H_

#include <string>
#include "Entities/Entity.h"
class Map {
 public:

  void load(std::string &filename);

  bool isEmpty(int x, int y) const;
  bool isInbound(int x, int y) const;

  void update(Event event, Entity *entity);
  void add(int x, int y, Entity *entity);

  // Just for testing
  std::string draw() const;
 private:
  int height;
  int width;

  int tiles[10][10];

  // Just for testing
  std::string getASCII(char type) const;
};

//Entity* entities[10][10] ?
//Terrain* terrain[10][10];

#endif
