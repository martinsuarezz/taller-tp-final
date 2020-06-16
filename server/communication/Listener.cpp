#include <iostream>
#include "Listener.h"
#include "ClientPeer.h"

Listener::Listener(std::string& port, World& world, EventQueue& queue)
  : world(world), queue(queue) {
  this->serverSocket.bind(port);
  this->serverSocket.listen(20);
}

void Listener::run() {
  while (!this->finished) {
    try {
    Socket clientSocket = std::move(this->serverSocket.accept());
    std::cout << "Cliente conectado\n";
    ClientPeer client(clientSocket, queue);
    client.start();
    } catch(SocketConnectionException& exception) {
      continue;
    }
  }
}

void Listener::finish() {
  this->finished = true;
}

Listener::~Listener() {
  this->serverSocket.close();
  this->join();
}