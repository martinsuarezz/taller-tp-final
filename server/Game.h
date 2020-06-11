#ifndef ARGENTUM__GAME_H_
#define ARGENTUM__GAME_H_

enum Event { MOVE };

#include <vector>
#include <map>

#include "Entities/Player.h"
#include "World.h"
#include "Entities/Creature.h"

class Game {
 public:
  Game();

  void addCharacter(std::string &name);
  void addCreature();

  std::string draw();
  void move(Player* player, int nextX, int nextY);

  bool isRunning() const;
  void stop();

  ~Game();

  // Just for testing
  Player * getPlayer(std::string &name);
 private:
  bool running;
  World world;
  std::map<std::string, Player *> players;
};

#endif
