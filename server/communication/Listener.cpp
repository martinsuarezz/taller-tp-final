#include <iostream>
#include "Listener.h"
#include "ClientPeer.h"

Listener::Listener(std::string& port, EventQueue& queue)
  : queue(queue) {
  this->serverSocket.bind(port);
  this->serverSocket.listen(20);
}

void Listener::run() {
  while (!this->finished) {
    try {
    Socket clientSocket = this->serverSocket.accept();
    std::cout << "Cliente conectado\n";
    auto* client = new ClientPeer(std::move(clientSocket), queue);
    client->start();
    clients.push_back(client);
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