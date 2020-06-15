#include "PlayerGraphic.h"
#include "AssetsLoader.h"
#include "AnimationIdle.h"
#include "AnimationWalkRight.h"
#include "Screen.h"

// CONSTRUCTOR TEMPORAL
PlayerGraphic::PlayerGraphic(AssetsLoader& assets):
                    assets(assets), animation(std::move(AnimationIdle(assets.getTexture(0), 400, 400))), x(400), y(400) {}

void PlayerGraphic::render(int frame, Screen& background){
    animation.render(frame, background);
}

void PlayerGraphic::moveRight(int distance){
    animation = std::move(AnimationWalkRight(assets.getTexture(0), x, y, x + distance, y));
    x += distance;
}

void PlayerGraphic::idle(){
    animation = std::move(AnimationIdle(assets.getTexture(0), x, y));
}