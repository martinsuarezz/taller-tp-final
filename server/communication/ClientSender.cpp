#include <iostream>
#include <zconf.h>
#include "ClientSender.h"

ClientSender::ClientSender(Socket socket, Queue<Message>& queue) : queue(queue) {
  this->clientSocket = std::move(socket);
  this->alive = true;
}

void ClientSender::run() {
  while(this->alive) {
    try {
      if(!queue.isEmpty()) {
        Message message = queue.pop();
        // send
      }
      usleep(1000000);
    } catch (SocketConnectionException &exception) {
      this->alive = false;
      std::cout << "Error conexion socket";
    }
  }
}

void ClientSender::push(Message& message) {
  queue.push(message);
}