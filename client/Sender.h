#ifndef SENDER_H
#define SENDER_H
#include "Thread.h"
#include "GameEntities/MovableEntity.h"
#include "GameMap.h"
#include "GameEntityContainer.h"

class Command;

class IntentionsQueue;

class CommandsQueue;

class MovableEntity;

class Sender: public Thread{
    private:
        IntentionsQueue& intentions;
        CommandsQueue& commands;
        GameMap map;
        GameEntityContainer entities;
        bool continueRunning;

    public:
        Sender(IntentionsQueue& intentions, CommandsQueue& commands,
                    std::string& race, std::string& name);
        void movePlayer(int direction);
        void stopMovementPlayer();
        void run();
        void addCommand(Command* command);
        void close();
        void pickUpItem();
        void interact();
        void buyItem(int itemIndex);
        void moveInventoryItem(int from, int to);
        void addItem(int itemId, int slot = -1);
        void attackEntity(int x, int y);
        void removeMob(int id);
        MovableEntity& getPlayer();

};

#endif
