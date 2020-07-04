#include <stdexcept>
#include "GameMap.h"
#include "GameEntities/GameEntity.h"
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 20
#define MAP_HEIGHT 20

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

std::pair<int, int> GameMap::getEmptyPosition(){
    if (entitiesAmmount == (width * height))
        throw std::runtime_error("No empty position");
    srand(time(NULL));
    int x = rand() % getWidth();
    int y = rand() % getHeight();
    while (!isEmpty(x, y)){
        x = rand() % getWidth();
        y = rand() % getHeight();
    }
    return std::make_pair(x, y);
}

int GameMap::getWidth() const{
    return width;
}

int GameMap::getHeight() const{
    return height;
}
