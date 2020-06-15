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

  void addCharacter(std::string &name);
  void addCreature();

  void move(int id, int nextX, int nextY);
  void attack(int id, int idEnemy);

  std::string draw();

  bool isRunning() const;
  void stop();

  ~Game();

  // Just for testing
  Creature *getCreature(int id);
  Player * getPlayer(std::string &name);
 private:
  int idCounter;
  bool running;
  World world;
  std::map<std::string, Player *> players;
};

#endif
