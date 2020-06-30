#include "IdleAction.h"
#include "Animation.h"
#include "Action.h"
#include "Entity.h"
#include "AssetsLoader.h"
#include "WalkingAction.h"
#include "Configuration.h"
#include <string>
#include <iostream>

WalkingAction::WalkingAction(Entity& entity, AssetsLoader& assets, std::string direction): Action(entity), assets(assets), direction(direction){
    Configuration& config = Configuration::getInstance();
    remainingFrames = (config.getValue("walking_duration") * config.getValue("fps")) / 1000;

    std::map<std::string, std::string>& equiped = entity.getEquipedItems();

    std::map<std::string, std::string>::iterator it;
    for (it = equiped.begin(); it != equiped.end(); it++){
        Texture& texture = assets.getTexture(it->second);
        std::string animationName = it->first.substr(1) + "_" + direction;
        std::vector<SDL_Rect>& frames = assets.getAnimationFrames(animationName);
        Animation bodyAnimation(texture, frames, 1000);
        animations.push_back(std::move(bodyAnimation));
    }
    
}
/*
void WalkingAction::updatePosition(){
    int pixelsToMove = (int) nearbyint((double)distance / (double)remainingFrames);
    if (direction == "up")
        entity.addY(-pixelsToMove);
    else if (direction == "right")
        entity.addX(pixelsToMove);
    else if (direction == "down")
        entity.addY(pixelsToMove);
    else if (direction == "left")
        entity.addX(-pixelsToMove);
    else
        std::cout << "Advertencia: dirección de movimiento errónea." << std::endl;

    distance -= pixelsToMove;
    remainingFrames--;
}
*/
void WalkingAction::update(){
    //this->updatePosition();
    this->render();
    if (remainingFrames <= 0)
        idle();
}

void WalkingAction::walk(std::string newDirection){
    if (newDirection == this->direction)
        return;
    entity.updateAction(new WalkingAction(entity, assets, newDirection));
}

void WalkingAction::idle(){
    entity.updateAction(new IdleAction(entity, assets));
}