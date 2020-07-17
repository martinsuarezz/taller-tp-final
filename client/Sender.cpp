#include "Sender.h"
#include "IntentionsQueue.h"
#include "Command/MoveCommand.h"
#include "Command/IdleCommand.h"
#include "Command/RemoveItemMapCommand.h"
#include "Command/Command.h"
#include "GameEntities/MovableEntity.h"
#include "GameMap.h"
#include "Intention/Intention.h"
#include "CommandsQueue.h"
#include "GameEntityContainer.h"
#include "Constants.h"
#include "Configuration.h"
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>

Sender::Sender(IntentionsQueue& intentions, CommandsQueue& commands, 
                std::string& race, std::string& type): 
    intentions(intentions), commands(commands), map(GameMap(*this, "mapFinal.json")),
    entities(GameEntityContainer(*this, map)), continueRunning(true){
    entities.addPlayer(20, 20, race, type);
    entities.addMob(18, 22, MERCHANT);
    entities.addMob(24, 22, HEALER);
}

void Sender::run(){
    std::unique_ptr<Intention> currentIntention;
    addItem(4, -1);
    addItem(5, -1);
    addItem(6, -1);
    addItem(7, -1);
    addItem(8, -1);
    addItem(9, -1);
    addItem(10, -1);
    addItem(SIMPLE_BOW_ID, -1);
    addItem(COMPOUND_BOW_ID, -1);
    addItem(IRON_SHIELD_ID, -1);
    addItem(TURTLE_SHIELD_ID, -1);
    //map.addItem(KNOT_STAFF_ID, 20, 20);
    while (continueRunning){
        currentIntention.reset(intentions.pop());
        currentIntention->execute(*this);
        entities.update(16667);
    }
}

void Sender::movePlayer(int direction){
    entities.move(0, direction);
}

void Sender::pickUpItem(){
    int x = entities.getMob(0)->getX();
    int y = entities.getMob(0)->getY();
    try{
        int itemId = map.getItemId(x, y);
        addItem(itemId);
        map.removeItem(x, y);
        addCommand(new RemoveItemMapCommand(x * 100, y * 100));
    }
    catch (std::out_of_range& e){
        std::cout << "Inventory is full!" << std::endl;
    }
    catch (std::runtime_error& e){}
}

void Sender::interact(){
    Configuration& config = Configuration::getInstance();
    MovableEntity& player = *entities.getMob(0);
    int x = player.getX();
    int y = player.getY();
    try{
        MovableEntity& entity = map.getInteractableEntity(x, y, config.getValue("interaction_range"));
        entity.interact(player);
    }
    catch (std::out_of_range& e){}
    catch (std::runtime_error& e){}
}

void Sender::buyItem(int itemIndex){
    Configuration& config = Configuration::getInstance();
    MovableEntity& player = *entities.getMob(0);
    int x = player.getX();
    int y = player.getY();
    try{
        MovableEntity& entity = map.getInteractableEntity(x, y, config.getValue("interaction_range"));
        entity.buyItem(player, itemIndex);
    }
    catch (std::out_of_range& e){}
    catch (std::runtime_error& e){}
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

MovableEntity& Sender::getPlayer(){
    return *entities.getMob(0);
}

void Sender::addCommand(Command* command){
    commands.push(command);
}

void Sender::close(){
    continueRunning = false;
}
