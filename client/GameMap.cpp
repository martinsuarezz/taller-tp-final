#include <stdexcept>
#include "GameMap.h"
#include "GameEntities/GameEntity.h"
#include "GameEntities/MovableEntity.h"
#include "RandomGenerator.h"
#include "MapTile.h"
#include <fstream>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

GameMap::GameMap(std::string mapFile): entitiesAmmount(0){
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
        if (layer1[i] != 0 || layer2[0] != 0)
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
    return !(getTile(x, y).isSolid()) && !(getTile(x, y).hasEntity())
            && isInbound(x, y);
}

void GameMap::addEntity(MovableEntity* entity, int x, int y){
    if (!isMobPlacable(x, y))
        throw std::runtime_error("Entity already in that space");
    getTile(x, y).addEntity(entity);
    entitiesAmmount++;
}

void GameMap::addItem(int itemId, int x, int y){
    getTile(x, y).addItem(itemId);
}

MapTile& GameMap::getTile(int x, int y){
    if (!isInbound(x, y))
        throw std::out_of_range("Trying to access tile out of bounds");
    return map.at(y * width + x);
}

bool GameMap::isInbound(int x, int y) const{
    return (x >= 0) && (x < width) && (y >= 0) && (y < height);
}

bool GameMap::canMove(int x, int y){
    return isMobPlacable(x, y) && isInbound(x, y);
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
