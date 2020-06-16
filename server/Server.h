#ifndef ARGENTUM_SERVER_SERVER_H_
#define ARGENTUM_SERVER_SERVER_H_

#include "communication/Listener.h"
#include "World.h"

class Server {
 public:
  explicit Server(std::string &port);

  void start();

  ~Server();
 private:
  Listener listener;
  World world;
  EventQueue queue;
};

#endif

