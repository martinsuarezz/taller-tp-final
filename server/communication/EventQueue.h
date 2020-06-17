#ifndef ARGENTUM_COMMUNICATION_QUEUE_H_
#define ARGENTUM_COMMUNICATION_QUEUE_H_

#include <mutex>
#include <queue>

#include "../events/Event.h"

class EventQueue {
 public:
  EventQueue();

  // Enqueue an event
  void push(Event& event);

  // Dequeue an event
  Event pop();

  // Close queue
  void close();

  bool isEmpty();
  bool isClosed();

  ~EventQueue();

 private:
  std::atomic<bool> closed;
  std::mutex m;
  std::queue<Event> queue;
  std::condition_variable cv;
};

#endif
