#ifndef RECEIVER_H
#define RECEIVER_H
#include "Thread.h"
#include "Package.h"

class CommandsQueue;

class Receiver: public Thread{
    private:
        CommandsQueue& commandsQueue;
        Package package;

    public:
        Receiver(CommandsQueue& queue);
        void receivePackage();
        void run();

};

#endif
