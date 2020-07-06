#include "Sender.h"
#include "IntentionsQueue.h"
#include "Command/MoveCommand.h"
#include "Command/IdleCommand.h"
#include "Command/Command.h"
#include "GameEntities/MovableEntity.h"
#include "GameMap.h"
#include "Intention/Intention.h"
#include "CommandsQueue.h"
#include "GameEntityContainer.h"
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <memory>
#include <string>

Sender::Sender(IntentionsQueue& intentions, CommandsQueue& commands): 
    intentions(intentions), commands(commands), entities(GameEntityContainer(*this, map)), continueRunning(true){}

void Sender::run(){
    std::unique_ptr<Intention> currentIntention;
    entities.addPlayer(20, 20);
    while (continueRunning){
        currentIntention.reset(intentions.pop());
        currentIntention->execute(*this);
        entities.update(16667);
    }
}

void Sender::movePlayer(int direction){
    entities.move(0, direction);
}

void Sender::stopMovementPlayer(){
    entities.stop(0);
}

void Sender::addCommand(Command* command){
    commands.push(command);
}

void Sender::close(){
    continueRunning = false;
}
