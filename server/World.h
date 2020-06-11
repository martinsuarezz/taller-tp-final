#ifndef ARGENTUM__MAP_H_
#define ARGENTUM__MAP_H_

#include <string>
#include <vector>

#include "Entities/Entity.h"

#define EMPTY ' '
#define TREE 'T'
#define PLAYER 'P'
#define CREATURE 'C'

class World {
 public:
  World();

  void load(std::string& filename);

  std::string draw() const;

  void addEntity(int x, int y, Entity *entity);

  void updateMap(Entity *entity);

  bool canMove(int x, int y) const;

  void notify(int event, Entity *sender);

 private:
  int height;
  int width;


  //Entity* entities[10][10] ?
  //Terrain* terrain[10][10];
  int map[10][10];


  std::vector<Entity *> entities;
  std::string drawObject(char type) const;

  bool isEmpty(int x, int y) const;
  bool isInbound(int x, int y) const;
};

#endif