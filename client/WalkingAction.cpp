#include "IdleAction.h"
#include "Animation.h"
#include "Action.h"
#include "PlayerGraphic.h"
#include "AssetsLoader.h"
#include "WalkingAction.h"
#include "Configuration.h"
#include <string>
#include <iostream>

WalkingAction::WalkingAction(PlayerGraphic& player, AssetsLoader& assets, std::string direction, int distance): Action(player), assets(assets), direction(direction), distance(distance){
    Configuration& config = Configuration::getInstance();
    remainingFrames = (config.getValue("walking_animation_duration") * config.getValue("fps")) / 1000;
    Texture& bodyTexture = player.getBodyAsset();
    std::vector<SDL_Rect>& frames = assets.getAnimationFrames("walking_animation_" + direction);

    Animation bodyAnimation(bodyTexture, frames, 1000);
    animations.push_back(std::move(bodyAnimation));
}

void WalkingAction::updatePosition(){
    int pixelsToMove = (int) nearbyint((double)distance / (double)remainingFrames);
    if (direction == "up")
        player.addY(-pixelsToMove);
    else if (direction == "right")
        player.addX(pixelsToMove);
    else if (direction == "down")
        player.addY(pixelsToMove);
    else if (direction == "left")
        player.addX(-pixelsToMove);
    else
        std::cout << "Advertencia: dirección de movimiento errónea." << std::endl;

    distance -= pixelsToMove;
    remainingFrames--;
}

void WalkingAction::update(){
    this->updatePosition();
    this->render();
    if (remainingFrames <= 0)
        player.updateAction(new IdleAction(player, assets));
}

void WalkingAction::walk(std::string direction, int distance){
    
}