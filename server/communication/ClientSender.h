#ifndef ARGENTUM_SERVER_COMMUNICATION_CLIENTSENDER_H_
#define ARGENTUM_SERVER_COMMUNICATION_CLIENTSENDER_H_

#include "Queue.h"
#include "Message.h"
#include "Socket.h"
#include "../Thread.h"

class ClientSender : public Thread {
 public:
  ClientSender(Socket socket, Queue<Message>& queue);
  void run() override;
  void push(Message& message);
 private:
  Socket clientSocket;
  bool alive;

  Queue<Message>& queue;
};

#endif
