#ifndef ARGENTUM_SERVER_CREATURE_H_
#define ARGENTUM_SERVER_CREATURE_H_

#include "Character.h"
#include "Player.h"

class Creature : public Character {
 public:
  Creature(World& map);
  void moveTo(Entity *entity);
};

#endif