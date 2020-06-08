#ifndef ARGENTUM__MAP_H_
#define ARGENTUM__MAP_H_

#include <string>
#include "Player.h"
#include "Creature.h"

class Map {
 public:
  Map();
  void loadMap();
  std::string draw() const;
  void addPlayer(Player* character);
  void update(int actualX, int actualY, int nextX, int nextY, int type);
  bool hasObstacle(int x, int y) const;
  bool isInbound(int x, int y);
  void addCreature(Creature *creature);
 private:
  int height;
  int width;
  int map[10][10];

  std::string drawObject(int type) const;
};

#endif