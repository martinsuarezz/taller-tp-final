#ifndef ARGENTUM__GAME_H_
#define ARGENTUM__GAME_H_

#include <vector>
#include "Player.h"
#include "Map.h"
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
  Player* player;
  std::vector<Creature*> creatures;
  Map* map;

  void notify();
};

#endif
