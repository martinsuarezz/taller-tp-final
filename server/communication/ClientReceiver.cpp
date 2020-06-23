#include <iostream>
#include "ClientReceiver.h"
#include "../Command.h"
#include "Queue.h"

ClientReceiver::ClientReceiver(Socket socket, Queue<Command>& queue) : queue(queue) {
  this->clientSocket = std::move(socket);
  this->alive = true;
}

void ClientReceiver::run() {
  while(this->alive) {
    try {
      std::string senderId = this->clientSocket.recv(1);
      std::string actionId = this->clientSocket.recv(1);
      std::string targetId = this->clientSocket.recv(1);

      Command event = Command
          (std::stoi(senderId), std::stoi(actionId), std::stoi(targetId));

      queue.push(event);
    } catch (SocketConnectionException& exception) {
      std::cout << "Cerrando cliente" << std::endl;
      this->alive = false;
    }
  }
}

bool ClientReceiver::isAlive() {
  return alive;
}

ClientReceiver::~ClientReceiver() {
  this->join();
}