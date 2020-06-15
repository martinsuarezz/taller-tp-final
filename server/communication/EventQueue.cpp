#include "EventQueue.h"

struct ClosedQueue : public std::exception {
  const char *what() const throw() {
    return "Queue is closed";
  }
};

EventQueue::EventQueue() {

}

void EventQueue::push(Event &event) {
  std::unique_lock<std::mutex> lk(m);
  queue.push(event);
  cv.notify_all();
}

Event EventQueue::pop() {
  std::unique_lock<std::mutex> lk(m);

  while (this->queue.empty()) {
    if (this->closed) {
      throw ClosedQueue();
    }

    cv.wait(lk);
  }

  Event event = queue.front();
  queue.pop();

  return event;
}

void EventQueue::close() {
  this->closed = true;
  cv.notify_all();
}

bool EventQueue::isClosed() {
  return this->closed;
}

bool EventQueue::isEmpty() {
  return this->queue.empty();
}

EventQueue::~EventQueue() {

}
