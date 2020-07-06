#include "IdleAction.h"
#include "WalkingAction.h"
#include "Action.h"
#include "../Animation/Animation.h"
#include "../AssetsLoader.h"
#include "../Entity.h"
#include <map>
#include <string>

IdleAction::IdleAction(Entity& entity, AssetsLoader& assets): 
                                    Action(entity), assets(assets){
    
    std::map<std::string, std::string>& equiped = entity.getEquipedItems();

    std::map<std::string, std::string>::iterator it;
    for (it = equiped.begin(); it != equiped.end(); it++){
        Texture& texture = assets.getTexture(it->second);
        std::string animationName = it->first.substr(1) + "_" + "idle";
        std::vector<SDL_Rect>& rect = assets.getAnimationFrames(animationName);
        Animation bodyAnimation(texture, rect, 1000);
        animations.push_back(std::move(bodyAnimation));
    }
}

void IdleAction::update(){
    this->render();
}

void IdleAction::walk(std::string direction){
    entity.updateAction(new WalkingAction(entity, assets, direction));
}

void IdleAction::idle(){}
