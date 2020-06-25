#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H
#include "Thread.h"

class CommandsQueue;

class Communicator: public Thread{
    private:
        CommandsQueue& commandsQueue;

    public:
        Communicator(CommandsQueue& queue);
        void run();

};

#endif
