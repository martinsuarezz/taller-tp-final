#ifndef ARGENTUM_COMMUNICATION_QUEUE_H_
#define ARGENTUM_COMMUNICATION_QUEUE_H_

#include <mutex>
#include <queue>

#include "../events/Command.h"

class EventQueue {
 public:
  EventQueue();

  // Enqueue an event
  void push(Command& event);

  // Dequeue an event
  Command pop();

  // Close queue
  void close();

  bool isEmpty();
  bool isClosed();

  ~EventQueue();

 private:
  std::atomic<bool> closed;
  std::mutex m;
  std::queue<Command> queue;
  std::condition_variable cv;
};

#endif
