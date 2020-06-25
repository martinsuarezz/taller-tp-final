#include "CommandsQueue.h"
#include "Command.h"
#include <mutex>

CommandsQueue::CommandsQueue(){}

Command* CommandsQueue::pop(){
    std::unique_lock<std::mutex> lock(m);
    Command* command = queue.front();
    queue.pop();
    return command;
}

void CommandsQueue::push(Command* command){
    std::unique_lock<std::mutex> lock(m);
    queue.push(command);
}

bool CommandsQueue::isEmpty(){
    std::unique_lock<std::mutex> lock(m);
    return queue.empty();
}