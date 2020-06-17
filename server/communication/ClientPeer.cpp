#include <iostream>
#include "ClientPeer.h"

ClientPeer::ClientPeer(Socket socket,
                       EventQueue &queue)
    : queue(queue) {
  this->clientSocket = std::move(socket);
  this->alive = true;
}

void ClientPeer::run() {
  while(this->alive) {
    try {

      std::string senderId = this->clientSocket.recv(1);
      std::string actionId = this->clientSocket.recv(1);

      Event event = Event(std::stoi(senderId), std::stoi(actionId));

      queue.push(event);
    } catch (SocketConnectionException& exception) {
      std::cout << "Cerrando cliente" << std::endl;
      this->alive = false;
    }
  }
}

bool ClientPeer::isAlive() {
  return this->alive;
}

ClientPeer::~ClientPeer() {
  this->clientSocket.close();
  this->join();
}

