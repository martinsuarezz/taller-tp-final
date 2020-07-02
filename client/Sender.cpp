#include "Sender.h"
#include "IntentionsQueue.h"
#include "MoveCommand.h"
#include "IdleCommand.h"
#include "Package.h"
#include "GameEntity.h"
#include "GameMap.h"
#include "Intention/Intention.h"
#include "GameEntity.h"
#include "Command.h"
#include "CommandsQueue.h"
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <memory>
#include <string>

Sender::Sender(IntentionsQueue& intentions, CommandsQueue& commands): 
intentions(intentions), commands(commands), player(GameEntity(*this, map, 1)), continueRunning(true){}

void Sender::run(){
    std::unique_ptr<Intention> currentIntention;
    map.addEntity(&player, 0, 0);
    while (continueRunning){
        currentIntention.reset(intentions.pop());
        currentIntention->execute(*this);
        player.update(16);
    }
}

void Sender::movePlayer(int direction){
    player.move(direction);
}

void Sender::addCommand(Command* command){
    commands.push(command);
}

void Sender::close(){
    continueRunning = false;
}