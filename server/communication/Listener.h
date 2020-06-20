#ifndef ARGENTUM_COMMUNICATION_LISTENER_H_
#define ARGENTUM_COMMUNICATION_LISTENER_H_

#include "../Thread.h"
#include "Socket.h"
#include "../World.h"
#include "ClientPeer.h"
#include "../Game.h"

class Listener : public Thread {
 public:
  explicit Listener(std::string& port, Game& game, EventQueue& queue);

  // Start thread
  void run() override;

  //Finishes thread execution. It allows exit while
  void finish();

  ~Listener();
 private:
  Socket serverSocket;

  Game& game;
  EventQueue& queue;

  bool finished;
};

#endif
