#ifndef ARGENTUM_COMMUNICATION_QUEUE_H_
#define ARGENTUM_COMMUNICATION_QUEUE_H_

#include <mutex>
#include <queue>

template<class T>
class Queue {
 public:
  Queue();

  // Enqueue a message
  void push(T &message);

  // Dequeue an event
  T pop();

  // Close queue
  void close();

  bool isEmpty();
  bool isClosed();

  ~Queue();

 private:
  std::atomic<bool> closed;
  std::mutex m;
  std::queue<T> queue;
  std::condition_variable cv;
};

struct ClosedQueue : public std::exception {
  const char *what() const throw() {
    return "Queue is closed";
  }
};

template<class T>
Queue<T>::Queue() : closed(false) {

}

template<class T>
void Queue<T>::push(T &message) {
  std::unique_lock<std::mutex> lk(m);
  queue.push(message);
  cv.notify_all();
}

template<class T>
T Queue<T>::pop() {
  std::unique_lock<std::mutex> lk(m);

  while (this->queue.empty()) {
    if (this->closed) {
      throw ClosedQueue();
    }

    cv.wait(lk);
  }

  T event = queue.front();
  queue.pop();

  return event;
}

template<class T>
void Queue<T>::close() {
  this->closed = true;
  cv.notify_all();
}

template<class T>
bool Queue<T>::isClosed() {
  return this->closed;
}

template<class T>
bool Queue<T>::isEmpty() {
  return this->queue.empty();
}

template<class T>
Queue<T>::~Queue() {

}

#endif
