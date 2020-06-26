#ifndef ARGENTUM_SERVER_SERVER_H_
#define ARGENTUM_SERVER_SERVER_H_

#include "communication/Listener.h"
#include "World.h"
#include "communication/GameLoop.h"
#include "Game.h"

class Server {
 public:
  explicit Server(std::string &port);

  void start();

  ~Server();
 private:
  Listener listener;
  Game game;
  Queue<Command> queue;
  GameLoop worker;
};

#endif

