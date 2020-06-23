#include <iostream>
#include "ClientSender.h"

ClientSender::ClientSender(Socket socket) {
  this->clientSocket = std::move(socket);
  this->alive = true;
}

void ClientSender::run() {
  while(this->alive) {
    try {
      if(!queue.isEmpty()) {
        ProtocolMessage message = queue.pop();
        // send
      }
    } catch (SocketConnectionException &exception) {
      this->alive = false;
      std::cout << "Error conexion socket";
    }
  }
}

void ClientSender::push(ProtocolMessage& message) {
  queue.push(message);
}