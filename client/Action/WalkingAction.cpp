#include "IdleAction.h"
#include "Action.h"
#include "WalkingAction.h"
#include "../Animation/Animation.h"
#include "../Entity.h"
#include "../AssetsLoader.h"
#include "../Configuration.h"
#include "../SoundPlayer.h"
#include <string>

WalkingAction::WalkingAction(Entity& entity, AssetsLoader& assets,
                            std::string direction): Action(entity),
                            assets(assets), direction(direction){
    std::map<std::string, std::string>& equiped = entity.getEquipedItems();

    Configuration& config = Configuration::getInstance();

    std::map<std::string, std::string>::iterator it;
    for (it = equiped.begin(); it != equiped.end(); it++){
        Texture& texture = assets.getTexture(it->second);
        std::string animationName = it->first.substr(1) + "_" + direction;
        std::vector<SDL_Rect>& frames = assets.getAnimationFrames(animationName);
        Animation bodyAnimation(texture, frames, 
                                config.getValue("anim_walking_duration"));
        animations.push_back(std::move(bodyAnimation));
    }
    
    sounds.push_back(SoundPlayer(assets.getSound("walking_sound"), 
                                config.getValue("sound_walking_time")));
}

void WalkingAction::playSounds(int timeElapsed){
    if (!entity.isOnScreen())
        return;
    std::vector<SoundPlayer>::iterator it;
    for (it = sounds.begin(); it != sounds.end(); it++)
        it->update(timeElapsed);
}

void WalkingAction::update(int timeElapsed){
    playSounds(timeElapsed);
    render(timeElapsed);
}

void WalkingAction::walk(std::string newDirection){
    if (newDirection == this->direction)
        return;
    entity.updateAction(new WalkingAction(entity, assets, newDirection));
}

void WalkingAction::idle(){
    entity.updateAction(new IdleAction(entity, assets));
}

void WalkingAction::refresh(){
    entity.updateAction(new WalkingAction(entity, assets, direction));
}
