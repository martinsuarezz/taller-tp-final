#include "PlayerGraphic.h"
#include "AssetsLoader.h"
#include "AnimationIdle.h"
#include "AnimationWalkRight.h"

// CONSTRUCTOR TEMPORAL
PlayerGraphic::PlayerGraphic(AssetsLoader& assets):
                    assets(assets), animation(std::move(AnimationIdle(assets.getTexture(0)))), x(5), y(5) {}

void PlayerGraphic::render(int frame){
    animation.render(x, y, frame);
}

void PlayerGraphic::moveRight(){
    animation = std::move(AnimationWalkRight(assets.getTexture(0)));
}

void PlayerGraphic::idle(){
    animation = std::move(AnimationIdle(assets.getTexture(0)));
}