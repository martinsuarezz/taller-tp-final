#ifndef ARGENTUM__GAME_H_
#define ARGENTUM__GAME_H_

#include <vector>
#include <map>

#include "entities/Player.h"
#include "World.h"
#include "entities/Creature.h"
#include "communication/ClientPeer.h"

class Game {
 public:
  Game();

  void pushClient(ClientPeer* client);

  void handle(Command& command);

  void notifyClients();

  std::string draw();

  ~Game();

 private:
  int idCounter;
  World world;
  std::vector<ClientPeer*> clients;
  std::map<std::string, Player *> players;

  void attack(int id, int idEnemy);
  void addPlayer(std::string name);
  void addCreature(int x, int y);
};

#endif
