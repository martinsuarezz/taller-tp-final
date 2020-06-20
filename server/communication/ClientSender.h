#ifndef ARGENTUM_SERVER_COMMUNICATION_CLIENTSENDER_H_
#define ARGENTUM_SERVER_COMMUNICATION_CLIENTSENDER_H_

#include "Socket.h"
#include "../Thread.h"

class ClientSender : public Thread {
 public:
  ClientSender(Socket socket);
  void run() override;
 private:
  Socket clientSocket;
  bool alive;
};

#endif
