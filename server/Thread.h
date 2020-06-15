#ifndef ARGENTUM_SERVER_THREAD_H_
#define ARGENTUM_SERVER_THREAD_H_

#include <thread>

class Thread {
 public:
  void start();
  void join();

  /**
  * Method to implement in character. It will run, after call start() method
  */
  virtual void run() = 0;
 private:
  std::thread thread;
};

#endif
