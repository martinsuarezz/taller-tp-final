#ifndef ARGENTUM__MAP_H_
#define ARGENTUM__MAP_H_

#include <string>
#include "Player.h"
#include "Creature.h"

#define EMPTY 0
#define TREE 1
#define PLAYER 2
#define CREATURE 3

#define TREE_STR "Arbol"
#define PLAYER_STR "Jugador"
#define CREATURE_STR "Criatura"

class Map {
 public:
  Map();
  void load(std::string& filename);
  std::string draw() const;
  void addPlayer(Player* character);
  void update(int actualX, int actualY, int nextX, int nextY, int type);
  bool hasObstacle(int x, int y) const;
  bool isInbound(int x, int y) const;
  void addCreature(Creature *creature);
 private:
  int height;
  int width;
  int map[10][10];

  std::string drawObject(int type) const;
  int getObject(std::string str) const;
};

#endif