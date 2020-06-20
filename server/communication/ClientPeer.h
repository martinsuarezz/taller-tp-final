#ifndef ARGENTUM_COMMUNICATION_CLIENTPEER_H_
#define ARGENTUM_COMMUNICATION_CLIENTPEER_H_

#include "../Thread.h"
#include "Queue.h"
#include "Socket.h"
#include "../World.h"
#include "ClientReceiver.h"
#include "ClientSender.h"

class ClientPeer {
 public:
  explicit ClientPeer(Socket socket, Queue<Command> &queue);

  /**
   * Run client peer thread
   */
  void run();

  ~ClientPeer();
 private:
  Socket clientSocket;
  Queue<Command> &queue;

  ClientReceiver receiver;
  ClientSender sender;
};

#endif
