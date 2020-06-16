#include <string>
#include <iostream>
#include "Server.h"

Server::Server(std::string &port) : listener(port, world, queue) {

}

void Server::start() {
  std::string input;

  listener.start();

  while (input != "q") {
    std::cin >> input;
  }

  listener.finish();
}

Server::~Server() {
}
