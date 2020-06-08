#ifndef ARGENTUM_SERVER_CREATURE_H_
#define ARGENTUM_SERVER_CREATURE_H_

#include "Character.h"
#include "Player.h"

class Creature : public Character {
 public:
  Creature();
  void moveTo(Player* player);
};

#endif