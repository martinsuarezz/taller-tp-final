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

  float dt = (float) 1/30; // 0.33

  std::cout << game.draw();

  while(this->running) {
    clock.start();

    // Execute commands
    while(!queue.isEmpty()) {
      Command command = queue.pop();
      game.handle(command);
    }

    // Update world
    game.update(dt);

    // Notify clients
    // game.notifyClients();

    clock.stop();

    float elapsedTime = clock.getDuration();
    float waitTime = dt - elapsedTime;

    if (waitTime > 0) {
      usleep(1000000);
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