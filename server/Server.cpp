#include <string>
#include <iostream>
#include "Server.h"

Server::Server(std::string &port) : listener(port, game, queue),
  worker(game, queue) {

}

void Server::start() {
  std::string input;

  worker.start();

  listener.start();

  while (input != "q") {
    std::cin >> input;
  }

  listener.finish();
  worker.stop();
}

Server::~Server() {

}
