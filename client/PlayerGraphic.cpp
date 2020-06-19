#include "PlayerGraphic.h"
#include "AssetsLoader.h"
#include "Screen.h"
#include "WalkingAnimation.h"
#include "IdleAnimation.h"
#include <iostream>

enum directions{UP, RIGHT, DOWN, LEFT};

// CONSTRUCTOR TEMPORAL
PlayerGraphic::PlayerGraphic(AssetsLoader& assets, int x, int y):
                    assets(assets), animation(new IdleAnimation(*this, assets)), x(x), y(y){
        //animation.reset(new IdleAnimation(*this));
}

void PlayerGraphic::render(Screen& background){
    animation->render(background);
}

void PlayerGraphic::addX(int pixels){
    x += pixels;
}

void PlayerGraphic::addY(int pixels){
    y += pixels;
}

void PlayerGraphic::moveUp(int distance) {
    animation->moveUp();
}

void PlayerGraphic::moveDown(int distance) {
    animation->moveDown();
}

void PlayerGraphic::moveRight(int distance){
    animation->moveRight();
}

void PlayerGraphic::moveLeft(int distance){
    animation->moveLeft();
}

void PlayerGraphic::idle(){
    animation.reset(new IdleAnimation(*this, assets));
}

int PlayerGraphic::getX(){
    return x;
}

int PlayerGraphic::getY(){
    return y;
}

void PlayerGraphic::updateAnimation(Animation* newAnimation){
    animation.reset(newAnimation);
}

Texture& PlayerGraphic::getBodyAsset(){
    std::string textureName = "player_sprite";
    return assets.getTexture(textureName);
}

Sound& PlayerGraphic::getSound(){
    std::string soundName = "walking_sound";
    return assets.getSound(soundName);
}