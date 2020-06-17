#include "EventWorker.h"
#include "EventQueue.h"

EventWorker::EventWorker(World& world, EventQueue& queue)
  : world(world), queue(queue) {
  this->running = true;
}

void EventWorker::run() {
  while(this->running) {
    this->proccess();
    std::this_thread::sleep_for(std::chrono::seconds(2));
  }
}

void EventWorker::process() {
  while(!queue.isEmpty()) {
    queue.pop();
  }
}

void EventWorker::stop() {
  this->running = false;
}

EventWorker::~EventWorker() {

}