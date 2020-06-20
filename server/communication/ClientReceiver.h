#ifndef ARGENTUM_SERVER_COMMUNICATION_CLIENTRECEIVER_H_
#define ARGENTUM_SERVER_COMMUNICATION_CLIENTRECEIVER_H_

#include "../Thread.h"
#include "Socket.h"
#include "EventQueue.h"

class ClientReceiver : public Thread {
 public:
  explicit ClientReceiver(Socket socket, EventQueue& queue);

  void run() override;

  bool isAlive();

  ~ClientReceiver();
 private:
  Socket clientSocket;
  EventQueue& queue;

  bool alive;
};

#endif