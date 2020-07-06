#include "IdleAction.h"
#include "Action.h"
#include "WalkingAction.h"
#include "../Animation/Animation.h"
#include "../Entity.h"
#include "../AssetsLoader.h"
#include "../Configuration.h"
#include "../SoundPlayer.h"
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

    sounds.push_back(SoundPlayer(assets.getSound("walking_sound"), 300));
}

void WalkingAction::update(){
    this->render();
    sounds[0].update(16);
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