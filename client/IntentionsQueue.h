#ifndef INTENION_QUEUE_H
#define INTENION_QUEUE_H
#include <queue>
#include <mutex>
#include <condition_variable>

class Intention;

class IntentionsQueue{
    private:
        std::queue<Intention*> queue;
        std::mutex m;
        std::condition_variable cv;
        bool isClosed;

    public:
        IntentionsQueue();
        Intention* pop();
        void push(Intention* intention);
        bool isEmpty();
        void close();

};

#endif
