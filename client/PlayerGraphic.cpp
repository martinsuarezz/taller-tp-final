#include "PlayerGraphic.h"
#include "AssetsLoader.h"
#include "AnimationIdle.h"
#include "AnimationWalkRight.h"

// CONSTRUCTOR TEMPORAL
PlayerGraphic::PlayerGraphic(AssetsLoader& assets):
                    assets(assets), animation(std::move(AnimationIdle(assets.getTexture(0), 5, 5))), x(5), y(5) {}

void PlayerGraphic::render(int frame){
    animation.render(frame);
}

void PlayerGraphic::moveRight(int distance){
    animation = std::move(AnimationWalkRight(assets.getTexture(0), x, y, x + distance, y));
    x += distance;
}

void PlayerGraphic::idle(){
    animation = std::move(AnimationIdle(assets.getTexture(0), x, y));
}