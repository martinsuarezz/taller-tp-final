#include "Entity.h"
#include "AssetsLoader.h"
#include "Screen.h"
#include "Action/IdleAction.h"
#include "Configuration.h"
#include <math.h>
#include <string>

Entity::Entity(AssetsLoader& assets, Screen& screen, 
                std::map<std::string, std::string> equiped, 
                std::string race, int x, int y): assets(assets), 
                screen(screen), equiped(equiped), 
                action(new IdleAction(*this, assets)), 
                race(race), x(x), y(y){}

void Entity::update(int timeElapsed){
    action->update(timeElapsed);
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
    Configuration& config = Configuration::getInstance();
    int tileSize = config.getValue("tile_size");
    int xOffset = config.getValue("mob_render_offset_x");
    return (int) nearbyint((float)(x * tileSize / 100)) + xOffset;
}

int Entity::getPixelsY() const{
    Configuration& config = Configuration::getInstance();
    int tileSize = config.getValue("tile_size");
    int yOffset = config.getValue("mob_render_offset_y");
    return (int) nearbyint((float)(y * tileSize / 100)) + yOffset;
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

void Entity::equipWeapon(int itemId){
    if (itemId == -1)
        equiped["3weapon"] = "";
    else
        equiped["3weapon"] = "item" + std::to_string(itemId);
    action->refresh();
}

void Entity::equipArmor(int itemId){
    if (itemId == -1)
        equiped["1body"] = race + "_body";
    else
        equiped["1body"] = "item" + std::to_string(itemId);
    action->refresh();
}

void Entity::equipShield(int itemId){
    if (itemId == -1)
        equiped["5weapon"] = "";
    else
        equiped["5weapon"] = "item" + std::to_string(itemId);
    action->refresh();
}

void Entity::equipHelmet(int itemId){
    if (itemId == -1)
        equiped["4head"] = "";
    else
        equiped["4head"] = "item" + std::to_string(itemId);
    action->refresh();
}

bool Entity::isOnScreen() const{
    return screen.isInbound(*this);
}

Entity::Entity(Entity&& other): assets(other.assets), screen(other.screen), 
                                equiped(other.equiped), race(other.race){
    this->x = other.x;
    this->y = other.y;
    this->action.reset(new IdleAction(*this, assets));
}
