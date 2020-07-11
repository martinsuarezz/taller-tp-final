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
#include "Constants.h"
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>

Sender::Sender(IntentionsQueue& intentions, CommandsQueue& commands): 
    intentions(intentions), commands(commands), entities(GameEntityContainer(*this, map)), continueRunning(true){}

void Sender::run(){
    std::unique_ptr<Intention> currentIntention;
    entities.addPlayer(20, 20);
    addItem(SWORD_ID, 1);
    addItem(AXE_ID, 2);
    addItem(HAMMER_ID, 3);
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

void Sender::moveInventoryItem(int from, int to){
    entities.moveInventoryItem(0, from, to);
}

void Sender::addItem(int itemId, int slot){
    entities.addItem(0, itemId, slot);
}

void Sender::attackEntity(int x, int y){
    try{
        int entityId = map.getEntityId(x, y);
        entities.attack(0, entityId);
    }
    catch (std::out_of_range& e) {}
}

void Sender::removeMob(int id){
    entities.removeMob(id);
}


void Sender::addCommand(Command* command){
    commands.push(command);
}

void Sender::close(){
    continueRunning = false;
}
