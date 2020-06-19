#include "Animation.h"
#include "Texture.h"
#include "Screen.h"
#include "Configuration.h"
#include <math.h>
#include <iostream>
#include <stdexcept>
#include "PlayerGraphic.h"
#include "AssetsLoader.h"

Animation::Animation(PlayerGraphic& player, AssetsLoader& assets): player(player), assets(assets){}

void Animation::render(Screen& screen){
    Texture& body = player.getBodyAsset();
    std::vector<SDL_Rect>& areas = assets.getAnimationFrames(animationName);
    Configuration& config = Configuration::getInstance();
    int milisecondsPerFrame = 1000 / config.getValue("fps");
    if (elapsedMiliseconds <= targetMiliseconds && (elapsedMiliseconds += milisecondsPerFrame) >= targetMiliseconds){
        currentAnimation++;
        targetMiliseconds += duration / animationFrames;
    }
    this->updatePosition();
    body.render(player.getX() - screen.getPositionX(), player.getY() - screen.getPositionY(), &areas[currentAnimation % areas.size()]);
    remainingFrames--;
    if (remainingFrames <= 0)
        player.idle();
}

Animation::~Animation(){

}