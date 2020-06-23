#include <iostream>
#include "ClientPeer.h"

ClientPeer::ClientPeer(Socket socket,
                       Queue<Command> &queue)
    : queue(queue), sender(std::move(socket)), receiver(std::move(socket), queue) {
  this->clientSocket = std::move(socket);
}

void ClientPeer::run() {
  sender.start();
  receiver.start();
}

void ClientPeer::notify(ProtocolMessage& message) {
  sender.push(message);
}

ClientPeer::~ClientPeer() {
  this->clientSocket.close();
}

