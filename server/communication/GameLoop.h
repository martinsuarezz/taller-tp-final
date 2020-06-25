#ifndef ARGENTUM_SERVER_COMMUNICATION_GAMELOOP_H_
#define ARGENTUM_SERVER_COMMUNICATION_GAMELOOP_H_

#include "../Thread.h"
#include "../World.h"
#include "Queue.h"
#include "../Game.h"

class GameLoop : public Thread {

 public:
  GameLoop(Game& game, Queue<Command> &queue);

  void run() override;

  void stop();

  ~GameLoop();
 private:
  Game& game;
  Queue<Command> &queue;

  bool running;
};

#endif
