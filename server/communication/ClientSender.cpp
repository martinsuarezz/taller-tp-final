#include "ClientSender.h"

ClientSender::ClientSender(Socket socket) {
  this->clientSocket = std::move(socket);
  this->alive = true;
}

void ClientSender::run() {
  for(;;) {
   try {

   } catch(SocketConnectionException& exception) {
     break;
   }
  }
}
