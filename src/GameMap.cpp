#include <stdexcept>
#include "GameMap.h"
#include "GameEntities/GameEntity.h"
#include "GameEntities/MovableEntity.h"
#include "Command/AddMapItemCommand.h"
#include "RandomGenerator.h"
#include "MapTile.h"
#include "Sender.h"
#include <fstream>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

GameMap::GameMap(Sender& game, std::string mapFile): game(game), 
                                            entitiesAmmount(0){
    std::ifstream file(std::string("maps/" + mapFile));
    json mapJSON;
    file >> mapJSON;

    width = mapJSON["width"];
    height = mapJSON["height"];

    map = std::vector<MapTile>(width * height, MapTile());

    json layers = mapJSON["layers"];
    std::vector<int> layer1(layers[1]["data"].get<std::vector<int>>());
    std::vector<int> layer2(layers[2]["data"].get<std::vector<int>>());

    for (int i = 0; i < width * height; i++){
        if (layer1[i] != 0 || layer2[i] != 0)
            setSolid(i);
    }
}

void GameMap::setSolid(int i){
    map[i].setSolid();
}

bool GameMap::moveEntity(int fromX, int fromY, int toX, int toY){
    if (!isMobPlacable(toX, toY))
        return false;
    getTile(toX, toY).transferEntity(getTile(fromX, fromY));
    return true;
}

void GameMap::remove(int fromX, int fromY){
    getTile(fromX, fromY).removeEntity();
}

bool GameMap::isMobPlacable(int x, int y){
    return isInbound(x, y) && 
            !(getTile(x, y).isSolid()) && 
            !(getTile(x, y).hasEntity());
}

void GameMap::addEntity(MovableEntity* entity, int x, int y){
    if (!isMobPlacable(x, y))
        throw std::runtime_error("Entity already in that space");
    getTile(x, y).addEntity(entity);
    entitiesAmmount++;
}

void GameMap::addItem(int itemId, int x, int y){
    getTile(x, y).addItem(itemId);
    game.addCommand(new AddMapItemCommand(itemId, x * 100, y * 100));
}

MapTile& GameMap::getTile(int x, int y){
    if (!isInbound(x, y))
        throw std::out_of_range("Trying to access tile out of bounds");
    return map.at(y * width + x);
}

bool GameMap::isInbound(int x, int y) const{
    return (x >= 0) && (x < width) && (y >= 0) && (y < height);
}

int GameMap::getEntityId(int x, int y){
    if (isMobPlacable(x, y) || !isInbound(x, y))
        throw std::out_of_range("No valid entity in that space");
    return getTile(x, y).getEntity()->getId();
}

int GameMap::getItemId(int x, int y){
    return getTile(x, y).getItemId();
}

void GameMap::removeItem(int x, int y){
    getTile(x, y).removeItem();
}

MovableEntity* GameMap::getEntity(int x, int y){
    MovableEntity* entity = getTile(x, y).getEntity();
    if (entity == nullptr)
        throw std::runtime_error("No entity at that coordinates");
    return entity;
}

MovableEntity& GameMap::getInteractableEntity(int x, int y, int range){
    MovableEntity* entity = nullptr;
    for (int i = x - range; i <= x + range; i++){
        for (int j = y - range; j <= y + range; j++){
            if (i == x && j == y)
                continue;
            try{
                entity = getEntity(i, j);
                if (!entity->isAlive())
                    return *entity;
            }
            catch(...) {}
        }
    }
    throw std::runtime_error("No available interactable entity");
    return *entity;
}

std::pair<int, int> GameMap::getEmptyPosition(){
    if (entitiesAmmount == (width * height))
        throw std::runtime_error("No empty position");
    
    RandomGenerator& random = RandomGenerator::getInstance();

    int x = random(getWidth());
    int y = random(getHeight());
    while (!isMobPlacable(x, y)){
        x = random(getWidth());
        y = random(getHeight());
    }
    return std::make_pair(x, y);
}

int GameMap::getWidth() const{
    return width;
}

int GameMap::getHeight() const{
    return height;
}
