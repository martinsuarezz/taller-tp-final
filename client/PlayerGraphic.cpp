#include "PlayerGraphic.h"
#include "AssetsLoader.h"
#include "AnimationIdle.h"
#include "AnimationWalkRight.h"
#define WALK_DISTANCE 20

// CONSTRUCTOR TEMPORAL
PlayerGraphic::PlayerGraphic(AssetsLoader& assets):
                    assets(assets), animation(std::move(AnimationIdle(assets.getTexture(0), 5, 5))), x(5), y(5) {}

void PlayerGraphic::render(int frame){
    animation.render(frame);
}

void PlayerGraphic::moveRight(){
    animation = std::move(AnimationWalkRight(assets.getTexture(0), x, y, x + WALK_DISTANCE, y));
    x += WALK_DISTANCE;
}

void PlayerGraphic::idle(){
    animation = std::move(AnimationIdle(assets.getTexture(0), x, y));
}