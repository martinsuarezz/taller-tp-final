#include "GameEntityContainer.h"
#include "GameEntities/MovableEntity.h"
#include "Command/SpawnMobCommand.h"
#include "Command/SpawnPlayerCommand.h"
#include "IdStack.h"
#include "GameMap.h"
#include "Sender.h"
#include "Constants.h"
#include <stdexcept>
#include <map>
#include <iostream>
#include <stdlib.h>
#include <tuple>

#define SPAWN_PROBABILITY 5
#define MAX_MOBS 10

GameEntityContainer::GameEntityContainer(Sender& game, GameMap& map): game(game), map(map), maxMobs(10){}

void GameEntityContainer::addPlayer(int x, int y){
    if (!map.isEmpty(x, y))
        throw std::runtime_error("Map not empty at indicated position");
    int id = ids.pop();
    mobs.emplace(id, std::move(MovableEntity(game, map, id, x, y)));
    map.addEntity(&(mobs.at(id)), x, y);
    game.addCommand(new SpawnPlayerCommand(id, x * 100, y * 100));
}

void GameEntityContainer::addMob(int x, int y, int type){
    if (!map.isEmpty(x, y))
        throw std::runtime_error("Map not empty at indicated position");
    int id = ids.pop();
    mobs.emplace(id, std::move(MovableEntity(game, map, id, x, y)));
    map.addEntity(&(mobs.at(id)), x, y);
    game.addCommand(new SpawnMobCommand(id, type, x * 100, y* 100));
}

void GameEntityContainer::update(int timeElapsed){
    spawnHostileMob();
    std::map<int, MovableEntity>::iterator it;
    for (it = mobs.begin(); it != mobs.end(); ++it){
        it->second.update(timeElapsed);
    }
}

MovableEntity& GameEntityContainer::getMob(int id){
    return mobs.at(id);
}

void GameEntityContainer::move(int id, int direction){
    getMob(id).move(direction);
}

void GameEntityContainer::stop(int id){
    getMob(id).stop();
}

void GameEntityContainer::spawnHostileMob(){
    if (rand() % 100 < SPAWN_PROBABILITY){
        try{
            std::pair<int, int> position = map.getEmptyPosition();
            addMob(position.first, position.second, ZOMBIE);
        }
        catch(std::runtime_error& e){}
    }
}