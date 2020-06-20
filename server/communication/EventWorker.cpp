#include <iostream>
#include "EventWorker.h"
#include "EventQueue.h"
#include "../entities/Player.h"

EventWorker::EventWorker(Game& game, EventQueue& queue)
  : game(game), queue(queue) {
  this->running = true;
}

void EventWorker::run() {
  std::cout << game.draw();
  while(this->running) {
    process();
    std::this_thread::sleep_for(std::chrono::seconds(5));
  }
}

void EventWorker::process() {
  while(!queue.isEmpty()) {
    Command event = queue.pop();

    game.handle(event);

    std::cout << game.draw();
  }

  game.notifyClients();
}

void EventWorker::stop() {
  this->running = false;
}

EventWorker::~EventWorker() {
  this->join();
}