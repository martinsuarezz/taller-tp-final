#ifndef COMMAND_QUEUE_H
#define COMMAND_QUEUE_H
#include <queue>
#include <mutex>

class Command;

class CommandsQueue{
    private:
        std::queue<Command*> queue;
        std::mutex m;

    public:
        CommandsQueue();
        Command* pop();
        void push(Command* command);
        bool isEmpty();

};

#endif
