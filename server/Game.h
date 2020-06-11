#ifndef ARGENTUM__GAME_H_
#define ARGENTUM__GAME_H_

enum Event { MOVE };

#include <vector>

#include "Player.h"
#include "World.h"
#include "Creature.h"

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
  Player * getPlayer();
 private:
  bool running;
  //Player* player;
  //std::vector<Creature*> creatures;
  World world;
};

#endif
