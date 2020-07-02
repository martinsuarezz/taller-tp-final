#include <stdexcept>
#include "GameMap.h"
#include "GameEntity.h"

bool GameMap::move(int fromX, int fromY, int toX, int toY){
    if (!isEmpty(toX, toY))
        return false;
    map[toX][toY] = map[fromX][fromY];
    remove(fromX, fromY);
    return true;
}

void GameMap::remove(int fromX, int fromY){
    if (isEmpty(fromX, fromY))
        throw std::runtime_error("No entity in specified tile");
    map[fromX][fromY] = NULL;
}

bool GameMap::isEmpty(int x, int y) const{
    return map[x][y] == NULL;
}

void GameMap::addEntity(GameEntity* entity, int x, int y){
    if (!isEmpty(x, y))
        throw std::runtime_error("Entity already in that space");
    map[x][y] = entity;
}
