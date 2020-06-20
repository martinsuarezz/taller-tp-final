#ifndef ARGENTUM_COMMUNICATION_CLIENTPEER_H_
#define ARGENTUM_COMMUNICATION_CLIENTPEER_H_

#include "../Thread.h"
#include "EventQueue.h"
#include "Socket.h"
#include "../World.h"
#include "ClientReceiver.h"
#include "ClientSender.h"

class ClientPeer {
 public:
  explicit ClientPeer(Socket socket, EventQueue& queue);

  /**
   * Run client peer thread
   */
  void run();

  ~ClientPeer();
 private:
  Socket clientSocket;
  EventQueue &queue;

  ClientReceiver receiver;
  ClientSender sender;
};

#endif
