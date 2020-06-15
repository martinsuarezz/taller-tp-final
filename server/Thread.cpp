#include "Thread.h"

void Thread::start() {
  this->thread = std::thread(&Thread::run, this);
}

void Thread::join() {
  this->thread.join();
}
