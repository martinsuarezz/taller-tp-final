#include "EntityContainer.h"
#include "AssetsLoader.h"
#include "Screen.h"
#include "Constants.h"
#include <stdexcept>

EntityContainer::EntityContainer(AssetsLoader& assets, Screen& screen): 
                    factory(EntityFactory(assets, screen)), playerId(-1){}

void EntityContainer::move(int entityId, int direction, int x, int y){
    Entity& entity = entities.at(entityId);
    switch(direction){
        case UP:
            entity.moveUp(x, y);
            break;
        case RIGHT:
            entity.moveRight(x, y);
            break;
        case DOWN:
            entity.moveDown(x, y);
            break;
        case LEFT:
            entity.moveLeft(x, y);
            break;
    }
}

void EntityContainer::idle(int entityId, int x, int y){
    entities.at(entityId).idle(x, y);
}

void EntityContainer::addMob(int entityId, int x, int y, int type){
    entities.emplace(entityId, factory.getZombie(x, y));
}

void EntityContainer::addPlayer(int entityId, int x, int y){
    entities.emplace(entityId, factory.getPlayer(x, y));
    if (playerId == -1)
        playerId = entityId;
}

void EntityContainer::removeMob(int entityId){
    entities.erase(entityId);
}

void EntityContainer::equipWeapon(int entityId, int itemId){
    entities.at(entityId).equipWeapon(itemId);
}

void EntityContainer::equipArmor(int entityId, int itemId){
    entities.at(entityId).equipArmor(itemId);
}

void EntityContainer::update(int timeElapsed){
    std::map<int, Entity>::iterator it;
    for (it = entities.begin(); it != entities.end(); it++){
        it->second.update(timeElapsed);
    }
}

Entity& EntityContainer::getPlayer(){
    if (playerId == -1){
        throw std::runtime_error("Player not set");
    }
    return entities.at(playerId);
}

//EntityContainer::~EntityContainer(){}
