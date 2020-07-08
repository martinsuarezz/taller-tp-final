#ifndef SENDER_H
#define SENDER_H
#include "Thread.h"
#include "GameEntities/MovableEntity.h"
#include "GameMap.h"
#include "GameEntityContainer.h"

class Command;

class IntentionsQueue;

class CommandsQueue;

class Sender: public Thread{
    private:
        IntentionsQueue& intentions;
        CommandsQueue& commands;
        GameMap map;
        GameEntityContainer entities;
        bool continueRunning;

    public:
        Sender(IntentionsQueue& intentions, CommandsQueue& commands);
        void movePlayer(int direction);
        void stopMovementPlayer();
        void run();
        void addCommand(Command* command);
        void close();
        void moveInventoryItem(int from, int to);
        void addItem(int itemId, int slot);
        void attackEntity(int x, int y);

};

#endif
