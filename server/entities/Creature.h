#ifndef ARGENTUM_SERVER_CREATURE_H_
#define ARGENTUM_SERVER_CREATURE_H_

#include "Character.h"
#include "Player.h"
#include "Item.h"

class Creature : public Character {
 public:
  Creature(World& world, int id, int x, int y);

  void react(Event event, Entity* sender) override;

  std::string toString() const override;

 private:
  void reactMove(Entity *sender);
  void moveToward(Entity *entity);
};

#endif