#include "Entity.h"
#include "AssetsLoader.h"
#include "Screen.h"
#include "Action/IdleAction.h"
#include <iostream>
#include <math.h>
#include <string>

#define TILE_SIZE 64

Entity::Entity(AssetsLoader& assets, Screen& screen, 
                std::map<std::string, std::string> equiped, 
                int x, int y): x(x), y(y), assets(assets), 
                screen(screen), equiped(equiped), 
                action(new IdleAction(*this, assets)){}

void Entity::update(){
    action->update();
}

void Entity::moveUp(int x, int y) {
    updatePosition(x, y);
    action->walk("up");
}

void Entity::moveDown(int x, int y) {
    updatePosition(x, y);
    action->walk("down");
}

void Entity::moveRight(int x, int y){
    updatePosition(x, y);
    action->walk("right");
}

void Entity::moveLeft(int x, int y){
    updatePosition(x, y);
    action->walk("left");
}

void Entity::idle(int x, int y){
    updatePosition(x, y);
    action->idle();
}

void Entity::updatePosition(int xNew, int yNew){
    x = xNew;
    y = yNew;
}

int Entity::getPixelsX() const{
    return (int) nearbyint((float)(x * TILE_SIZE / 100)) + 12;
}

int Entity::getPixelsY() const{
    return (int) nearbyint((float)(y * TILE_SIZE / 100)) + 12;
}

int Entity::getRelativeX() const{
    return getPixelsX() - screen.getPositionX();
}

int Entity::getRelativeY() const{
    return getPixelsY() - screen.getPositionY();
}

void Entity::updateAction(Action* newAction){
    action.reset(newAction);
}

std::map<std::string, std::string>& Entity::getEquipedItems(){
    return equiped;
}

bool Entity::isOnScreen() const{
    return screen.isInbound(*this);
}

Entity::Entity(Entity&& other): assets(other.assets), screen(other.screen), 
                                equiped(other.equiped){
    this->x = other.x;
    this->y = other.y;
    this->action.reset(new IdleAction(*this, assets));
}
