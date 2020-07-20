#include "MapTile.h"
#include "GameEntities/MovableEntity.h"
#include <stdexcept>

MapTile::MapTile(): entity(nullptr), item(-1), solid(false) {}

void MapTile::setSolid(){
    solid = true;
}

void MapTile::transferEntity(MapTile& other){
    this->entity = other.entity;
    other.entity = nullptr;
}

void MapTile::removeEntity(){
    entity = nullptr;
}

void MapTile::addEntity(MovableEntity* newEntity){
    this->entity = newEntity;
}

bool MapTile::isSolid(){
    return solid;
}

bool MapTile::hasEntity(){
    return entity != nullptr;
}

MovableEntity* MapTile::getEntity(){
    return entity;
}

int MapTile::getItemId(){
    if (item == -1)
        throw std::runtime_error("No item is this tile");
    return item;
}

void MapTile::removeItem(){
    item = -1;
}

void MapTile::addItem(int itemId){
    item = itemId;
}
