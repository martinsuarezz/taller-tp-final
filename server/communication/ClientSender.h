#ifndef ARGENTUM_SERVER_COMMUNICATION_CLIENTSENDER_H_
#define ARGENTUM_SERVER_COMMUNICATION_CLIENTSENDER_H_

#include "Queue.h"
#include "ProtocolMessage.h"
#include "Socket.h"
#include "../Thread.h"

class ClientSender : public Thread {
 public:
  ClientSender(Socket socket);
  void run() override;
  void push(ProtocolMessage& message);
 private:
  Socket clientSocket;
  bool alive;

  Queue<ProtocolMessage> queue;
};

#endif
