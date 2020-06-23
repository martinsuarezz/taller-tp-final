#ifndef ARGENTUM_SERVER_COMMUNICATION_EVENTWORKER_H_
#define ARGENTUM_SERVER_COMMUNICATION_EVENTWORKER_H_

#include "../Thread.h"
#include "../World.h"
#include "Queue.h"
#include "../Game.h"

class EventWorker : public Thread {

 public:
  EventWorker(Game& game, Queue<Command> &queue);

  void run() override;

  void stop();

  ~EventWorker();
 private:
  Game& game;
  Queue<Command> &queue;

  bool running;

  // Initialize to consume queue
  void process();
};

#endif
