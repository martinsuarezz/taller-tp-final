#ifndef ARGENTUM_SERVER_COMMUNICATION_EVENTWORKER_H_
#define ARGENTUM_SERVER_COMMUNICATION_EVENTWORKER_H_

#include "../Thread.h"
#include "../World.h"
#include "EventQueue.h"

class EventWorker : public Thread {

 public:
  EventWorker(World& world, EventQueue& queue);

  void run() override;

  void stop();

  ~EventWorker();
 private:
  World& world;
  EventQueue& queue;

  bool running;

  // Initialize to consume queue
  void process();
};

#endif
