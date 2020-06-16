#include <iostream>

#include "Game.h"
#include "Server.h"

int main() {
  std::string port("9000");

  Server server(port);

  server.start();

  return 0;
}