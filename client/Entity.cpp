#include "Entity.h"
#include "AssetsLoader.h"
#include "Screen.h"
#include "IdleAction.h"
#include <iostream>
#include <string>

Entity::Entity(AssetsLoader& assets, Screen& screen, std::map<std::string, std::string> equiped, int x, int y):
                    x(x), y(y), assets(assets), screen(screen), equiped(equiped), action(new IdleAction(*this, assets)){
    
}

void Entity::update(){
    action->update();
}

void Entity::addX(int pixels){
    x += pixels;
}

void Entity::addY(int pixels){
    y += pixels;
}

void Entity::moveUp(int x, int y) {
    this->x = x;
    this->y = y;
    action->walk("up");
}

void Entity::moveDown(int x, int y) {
    this->x = x;
    this->y = y;
    action->walk("down");
}

void Entity::moveRight(int x, int y){
    this->x = x;
    this->y = y;
    action->walk("right");
}

void Entity::moveLeft(int x, int y){
    this->x = x;
    this->y = y;
    action->walk("left");
}

int Entity::getX() const{
    return x;
}

int Entity::getY() const{
    return y;
}

int Entity::getRelativeX() const{
    return this->getX() - screen.getPositionX();
}

int Entity::getRelativeY() const{
    return this->getY() - screen.getPositionY();
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

Entity::Entity(Entity&& other): assets(other.assets), screen(other.screen), equiped(other.equiped){
    this->x = other.x;
    this->y = other.y;
    this->action.reset(new IdleAction(*this, assets));
}
