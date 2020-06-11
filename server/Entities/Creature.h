#ifndef ARGENTUM_SERVER_CREATURE_H_
#define ARGENTUM_SERVER_CREATURE_H_

#include "Character.h"
#include "Player.h"

class Creature : public Character {
 public:
  Creature(World& world);
  void moveToward(Entity *entity);
  void react(int event, Entity* sender) override;
 private:
  void reactMove(Entity *sender);
};

#endif