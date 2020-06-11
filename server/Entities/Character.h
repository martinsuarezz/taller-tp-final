#ifndef ARGENTUM_SERVER_CHARACTER_H_
#define ARGENTUM_SERVER_CHARACTER_H_

#include "../World.h"

class Character : public Entity {
 public:
  Character(World &world);
  void move(int nextX, int nextY);
  bool isNextTo(Character *character);
  bool isNearFrom(Character* character);
  void react(int event, Entity* sender) override = 0;
 protected:
  World& world;
};

#endif
