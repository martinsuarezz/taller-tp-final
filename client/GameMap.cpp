#include <stdexcept>
#include "GameMap.h"
#include "GameEntities/GameEntity.h"
#include "GameEntities/MovableEntity.h"
#include "RandomGenerator.h"
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 50

GameMap::GameMap(): width(MAP_WIDTH), height(MAP_HEIGHT), entitiesAmmount(0){
    for (int i = 0; i < MAP_WIDTH; i++){
        for (int j = 0; j < MAP_HEIGHT; j++){
            map[i][j] = NULL;
        }
    }
}

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
    entitiesAmmount++;
}

bool GameMap::isInbound(int x, int y) const{
    return (x >= 0) && (x < width) && (y >= 0) && (y < height);
}

bool GameMap::canMove(int x, int y) const{
    return isEmpty(x, y) && isInbound(x, y);
}

int GameMap::getEntityId(int x, int y) const{
    if (isEmpty(x, y) || !isInbound(x, y))
        throw std::out_of_range("No valid entity in that space");
    MovableEntity* entity = (MovableEntity*) map[x][y];
    return entity->getId();
}

std::pair<int, int> GameMap::getEmptyPosition(){
    if (entitiesAmmount == (width * height))
        throw std::runtime_error("No empty position");
    
    RandomGenerator& random = RandomGenerator::getInstance();

    int x = random(getWidth());
    int y = random(getHeight());
    while (!isEmpty(x, y)){
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
