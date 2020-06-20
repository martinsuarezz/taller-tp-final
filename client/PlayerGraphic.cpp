#include "PlayerGraphic.h"
#include "AssetsLoader.h"
#include "Screen.h"
#include "IdleAction.h"
#include <iostream>
#include <string>

PlayerGraphic::PlayerGraphic(AssetsLoader& assets, Screen& screen, int x, int y):
                    x(x), y(y), assets(assets), screen(screen), action(new IdleAction(*this, assets)){

}

void PlayerGraphic::render(){
    action->update();
}

void PlayerGraphic::addX(int pixels){
    x += pixels;
}

void PlayerGraphic::addY(int pixels){
    y += pixels;
}

void PlayerGraphic::moveUp(int distance) {
    action->walk("up", distance);
}

void PlayerGraphic::moveDown(int distance) {
    action->walk("down", distance);
}

void PlayerGraphic::moveRight(int distance){
    action->walk("right", distance);
}

void PlayerGraphic::moveLeft(int distance){
    action->walk("left", distance);
}

int PlayerGraphic::getX() const{
    return x;
}

int PlayerGraphic::getY() const{
    return y;
}

int PlayerGraphic::getRelativeX() const{
    return this->getX() - screen.getPositionX();
}

int PlayerGraphic::getRelativeY() const{
    return this->getY() - screen.getPositionY();
}

void PlayerGraphic::updateAction(Action* newAction){
    action.reset(newAction);
}

Texture& PlayerGraphic::getBodyAsset(){
    std::string textureName = "player_sprite";
    return assets.getTexture(textureName);
}
/*
Texture& PlayerGraphic::getHeadAsset(){
    std::string textureName = "face_human";
    return assets.getTexture(textureName);
}
*/
Sound& PlayerGraphic::getSound(){
    std::string soundName = "walking_sound";
    return assets.getSound(soundName);
}