#include <iostream>
#include "ClientPeer.h"

ClientPeer::ClientPeer(Socket socket,
                       Queue<Command> &queue)
    : commandsQueue(queue), sender(std::move(socket), clientQueue), receiver(std::move(socket), queue) {
  this->clientSocket = std::move(socket);
}

void ClientPeer::run() {
  sender.start();
  receiver.start();
}

void ClientPeer::notify(Message& message) {
  clientQueue.push(message);
}

ClientPeer::~ClientPeer() {
  this->clientSocket.close();
}

