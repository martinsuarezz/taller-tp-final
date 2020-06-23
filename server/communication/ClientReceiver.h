#ifndef ARGENTUM_SERVER_COMMUNICATION_CLIENTRECEIVER_H_
#define ARGENTUM_SERVER_COMMUNICATION_CLIENTRECEIVER_H_

#include "../Thread.h"
#include "Socket.h"
#include "Queue.h"
#include "../Command.h"

class ClientReceiver : public Thread {
 public:
  explicit ClientReceiver(Socket socket, Queue<Command> &queue);

  void run() override;

  bool isAlive();

  ~ClientReceiver();
 private:
  Socket clientSocket;
  Queue<Command> &queue;

  bool alive;
};

#endif