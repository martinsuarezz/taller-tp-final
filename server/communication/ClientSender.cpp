#include "ClientSender.h"

ClientSender::ClientSender(Socket socket) {
  this->clientSocket = std::move(socket);
  this->alive = true;
}

void ClientSender::send(std::string& message) {
  clientSocket.send(message);
}
