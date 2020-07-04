#include "IntentionsQueue.h"
#include "Intention/Intention.h"
#include <queue>
#include <mutex>
#include <condition_variable>
#include <stdexcept>
#include <iostream>

IntentionsQueue::IntentionsQueue(): isClosed(false){}

Intention* IntentionsQueue::pop(){
    std::unique_lock<std::mutex> lock(m);

    while (queue.empty()){
        if (isClosed){
            throw std::runtime_error("Closed queue");
        }
        cv.wait(lock);
    }

    Intention* intention = queue.front();
    queue.pop();
    return intention;
}

void IntentionsQueue::push(Intention* intention){
    std::unique_lock<std::mutex> lock(m);
    queue.push(intention);
    cv.notify_all();
}

bool IntentionsQueue::isEmpty(){
    std::unique_lock<std::mutex> lock(m);
    return queue.empty();
}

void IntentionsQueue::close(){
    isClosed = true;
    cv.notify_all();
}
