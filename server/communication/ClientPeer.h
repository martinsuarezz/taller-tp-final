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
   * Run client sender and client receiver
   */
  void run();

  /**
   * Notify message to a client
   * @param message
   */
  void notify(Message &message);

  ~ClientPeer();
 private:
  Socket clientSocket;

  // Global clientQueue to push commands
  Queue<Command> &commandsQueue;

  // Queue to notify client
  Queue<Message> clientQueue;

  ClientReceiver receiver;
  ClientSender sender;
};

#endif
