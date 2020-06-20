#include "IdleAction.h"
#include "Animation.h"
#include "Action.h"
#include "PlayerGraphic.h"
#include "AssetsLoader.h"
#include "WalkingAction.h"
#include <iostream>

IdleAction::IdleAction(PlayerGraphic& player, AssetsLoader& assets): Action(player), assets(assets){
    Texture& bodyTexture = player.getBodyAsset();
    std::vector<SDL_Rect>& frames = assets.getAnimationFrames("idle_animation");

    Animation bodyAnimation(bodyTexture, frames, 1000);
    animations.push_back(std::move(bodyAnimation));
}

void IdleAction::update(){
    this->render();
}

void IdleAction::walk(std::string direction, int distance){
    player.updateAction(new WalkingAction(player, assets, direction, distance));
}