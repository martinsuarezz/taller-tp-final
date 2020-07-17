#include "GameEntityContainer.h"
#include "GameEntities/MovableEntity.h"
#include "GameEntities/Player.h"
#include "GameEntities/Zombie.h"
#include "Command/SpawnMobCommand.h"
#include "Command/SpawnPlayerCommand.h"
#include "Command/RemoveMobCommand.h"
#include "IdStack.h"
#include "GameMap.h"
#include "Configuration.h"
#include "Sender.h"
#include "Constants.h"
#include "RandomGenerator.h"
#include <stdexcept>
#include <map>
#include <iostream>
#include <stdlib.h>
#include <tuple>

GameEntityContainer::GameEntityContainer(Sender& game, GameMap& map): 
                        game(game), map(map), maxMobs(0),
                        factory(GameEntityFactory(game, map, *this)){

    Configuration& config = Configuration::getInstance();
    maxMobs = (size_t) config.getValue("mob_spawn_max");
    mobSpawnProb = config.getValue("mob_spawn_prob");
}

void GameEntityContainer::addPlayer(int x, int y, std::string& race, std::string& type){
    if (!map.isMobPlacable(x, y))
        throw std::runtime_error("Map can't place mob at indicated position");
    int id = ids.pop();
    mobs.emplace(id, factory.getPlayer(x, y, id, race, type));
    map.addEntity((mobs.at(id)), x, y);
    game.addCommand(new SpawnPlayerCommand(id, x * 100, y * 100, race));
}

void GameEntityContainer::addMob(int x, int y, int type){
    if (!map.isMobPlacable(x, y))
        throw std::runtime_error("Map can't place mob at indicated position");
    int id = ids.pop();
    switch (type){
        case ZOMBIE:
            mobs.emplace(id, factory.getZombie(x, y, id));
            map.addEntity((mobs.at(id)), x, y);
            break;
        case MERCHANT:
            mobs.emplace(id, factory.getMerchant(x, y, id));
            map.addEntity((mobs.at(id)), x, y);
            break;
        case HEALER:
            mobs.emplace(id, factory.getHealer(x, y, id));
            map.addEntity((mobs.at(id)), x, y);
            break;
        default:
            std::cout << "Warning: mob of id " << type << " not implemented." << std::endl;
            return;
    }
    
    game.addCommand(new SpawnMobCommand(id, type, x * 100, y* 100));
}

void GameEntityContainer::removeMob(int id){
    MovableEntity* entity = mobs.at(id);
    map.remove(entity->getX(), entity->getY());
    mobs.erase(id);
    ids.push(id);
    delete entity;
    game.addCommand(new RemoveMobCommand(id));
}

void GameEntityContainer::update(int timeElapsed){
    spawnHostileMob();
    std::map<int, MovableEntity*>::iterator it;
    for (it = mobs.begin(); it != mobs.end(); ++it){
        it->second->update(timeElapsed);
    }
}

MovableEntity* GameEntityContainer::getMob(int id){
    return mobs.at(id);
}

void GameEntityContainer::move(int id, int direction){
    getMob(id)->move(direction);
}

void GameEntityContainer::stop(int id){
    getMob(id)->stop();
}

void GameEntityContainer::notifyPlayerMovement(int x, int y){
    std::map<int, MovableEntity*>::iterator it;
    for (it = mobs.begin(); it != mobs.end(); it++){
        it->second->notifyPlayerMovement(x, y);
    }
}

void GameEntityContainer::spawnHostileMob(){
    RandomGenerator& random = RandomGenerator::getInstance();
    if ((mobs.size() < maxMobs) && (random(100) < mobSpawnProb)){
        try{
            std::pair<int, int> position = map.getEmptyPosition();
            addMob(position.first, position.second, ZOMBIE);
        }
        catch(std::runtime_error& e){}
    }
}

void GameEntityContainer::moveInventoryItem(int id, int from, int to){
    getMob(id)->moveInventoryItem(from, to);
}

void GameEntityContainer::attack(int from, int to){
    mobs.at(from)->attackEntity(*mobs.at(to));
}

void GameEntityContainer::addItem(int entityId, int itemId, int slot){
    getMob(entityId)->addItem(itemId, slot);
}

GameEntityContainer::~GameEntityContainer(){
    std::map<int, MovableEntity*>::iterator it;
    for (it = mobs.begin(); it != mobs.end(); it++){
        delete it->second;
    }
}
