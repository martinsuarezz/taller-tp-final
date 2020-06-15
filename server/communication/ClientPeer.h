#ifndef ARGENTUM_COMMUNICATION_CLIENTPEER_H_
#define ARGENTUM_COMMUNICATION_CLIENTPEER_H_

#include "../Thread.h"
#include "EventQueue.h"
#include "Socket.h"
#include "../World.h"

class ClientPeer : public Thread {
 public:
  explicit ClientPeer(Socket &socket, EventQueue& queue);

  /**
   * Run client peer thread
   */
  void run() override;

  bool isAlive();

  virtual ~ClientPeer();
 private:
  bool alive;
  EventQueue &queue;
  Socket &clientSocket;
};

#endif
