#ifndef ARGENTUM__MAP_H_
#define ARGENTUM__MAP_H_

#include <string>

#include "Entity.h"

#define EMPTY ' '
#define TREE 'T'
#define PLAYER 'P'
#define CREATURE 'C'

#define TREE_STR "Arbol"
#define PLAYER_STR "Jugador"
#define CREATURE_STR "Criatura"

class World {
 public:
  World();

  void load(std::string& filename);

  std::string draw() const;

  void addEntity(Entity *entity, int x, int y);

  void moveTo(int nextY, int nextX, Entity *character);

  bool isEmpty(int x, int y) const;

  bool isInbound(int x, int y) const;

 private:
  int height;
  int width;
  int map[10][10];

  void notify(int event, Entity *entity);

  //std::vector<Entity *> entities;
  std::string drawObject(int type) const;
  int getObject(std::string str) const;
};

#endif