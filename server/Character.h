#ifndef ARGENTUM_SERVER_CHARACTER_H_
#define ARGENTUM_SERVER_CHARACTER_H_

#include "World.h"

class Character : public Entity {
 public:
  Character(World &map);
  void move(int nextX, int nextY);
  bool isNextTo(Character *character);
  bool isNearFrom(Character* character);
 protected:
  World& map;
  void notify();
};

#endif
