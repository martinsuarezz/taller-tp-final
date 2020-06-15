#include <iostream>
#include "ClientPeer.h"

ClientPeer::ClientPeer(Socket &socket, EventQueue &queue)
    : queue(queue), clientSocket(socket) {
  this->alive = true;
}

void ClientPeer::run() {
  while(this->alive) {
    try {
      std::cout << "Esperando..." << std::endl;
      std::string receive = this->clientSocket.recv(1);
      std::cout << "Mensaje recibido: "<< std::endl;
      std::cout << receive;
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

