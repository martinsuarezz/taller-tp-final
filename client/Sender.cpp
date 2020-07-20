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
    entities.addPlayer(2, 2, race, type);
    entities.addMob(18, 22, MERCHANT);
    entities.addMob(24, 22, HEALER);
}

void Sender::run(){
    try{
        std::unique_ptr<Intention> currentIntention;
        addItem(IRON_SHIELD_ID, -1);
        addItem(SWORD_ID, -1);
        addItem(PLATE_ARMOR_ID, -1);
        addItem(ELFIC_FLUTE_ID, -1);
        addItem(ICE_STAFF_ID, -1);
        Configuration& config = Configuration::getInstance();
        int microsecondsPerFrame = MICROS_IN_SECOND / config.getValue("fps");

        while (continueRunning){
            currentIntention.reset(intentions.pop());
            currentIntention->execute(*this);
            entities.update(microsecondsPerFrame);
        }
    }
    catch(...){}
}

void Sender::movePlayer(int direction){
    entities.move(PLAYER_ID, direction);
}

void Sender::pickUpItem(){
    int x = entities.getMob(PLAYER_ID)->getX();
    int y = entities.getMob(PLAYER_ID)->getY();
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
    MovableEntity& player = *entities.getMob(PLAYER_ID);
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
    MovableEntity& player = *entities.getMob(PLAYER_ID);
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
    entities.stop(PLAYER_ID);
}

void Sender::moveInventoryItem(int from, int to){
    entities.moveInventoryItem(PLAYER_ID, from, to);
}

void Sender::addItem(int itemId, int slot){
    entities.addItem(PLAYER_ID, itemId, slot);
}

void Sender::tossItem(int slot){
    MovableEntity& player = *entities.getMob(PLAYER_ID);
    try{
        int item = player.removeItem(slot);
        map.addItem(item, player.getX(), player.getY());
    }
    catch(std::runtime_error& e){}
}

void Sender::attackEntity(int x, int y){
    try{
        int entityId = map.getEntityId(x, y);
        entities.attack(PLAYER_ID, entityId);
    }
    catch (std::out_of_range& e) {}
}

void Sender::removeMob(int id){
    entities.removeMob(id);
}

MovableEntity& Sender::getPlayer(){
    return *entities.getMob(PLAYER_ID);
}

void Sender::addCommand(Command* command){
    commands.push(command);
}

void Sender::close(){
    continueRunning = false;
}
