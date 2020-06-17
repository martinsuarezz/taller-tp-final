#ifndef ARGENTUM__GAME_H_
#define ARGENTUM__GAME_H_

#include <vector>
#include <map>

#include "entities/Player.h"
#include "World.h"
#include "entities/Creature.h"

class Game {
 public:
  Game();

  void handle(Event& event);

  std::string draw();

  ~Game();

 private:
  int idCounter;
  World world;
  std::map<std::string, Player *> players;

  void attack(int id, int idEnemy);
  void addPlayer(std::string name);
  void addCreature();
};

#endif
