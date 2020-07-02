#ifndef SENDER_H
#define SENDER_H
#include "Thread.h"
#include "Package.h"
#include "GameEntity.h"
#include "GameMap.h"

class Command;

class IntentionsQueue;

class CommandsQueue;

class Sender: public Thread{
    private:
        IntentionsQueue& intentions;
        CommandsQueue& commands;
        GameMap map;
        GameEntity player;
        bool continueRunning;

    public:
        Sender(IntentionsQueue& intentions, CommandsQueue& commands);
        void movePlayer(int direction);
        void run();
        void addCommand(Command* command);
        void close();

};

#endif
