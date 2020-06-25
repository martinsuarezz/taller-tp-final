#include <iostream>
#include <zconf.h>
#include "GameLoop.h"
#include "../entities/Player.h"
#include "../../common/Clock.h"

GameLoop::GameLoop(Game& game, Queue<Command>& queue)
  : game(game), queue(queue) {
  this->running = true;
}

void GameLoop::run() {
  Clock clock;

  int dt = 1000000 / 30; // time step

  std::cout << game.draw();

  while(this->running) {
    clock.start();

    // Execute commands
    while(!queue.isEmpty()) {
      Command command = queue.pop();
      game.handle(command);
    }

    // Update world
    // game.update(dt);

    clock.stop();

    int elapsedTime = clock.getDuration();
    int waitTime = dt - elapsedTime;

    if (waitTime > 0) {
      usleep(waitTime);
    }

    std::cout << game.draw();
  }
}

void GameLoop::stop() {
  this->running = false;
}

GameLoop::~GameLoop() {
  this->join();
}