#include "PlayerGraphic.h"
#include "AssetsLoader.h"
#include "AnimationIdle.h"
#include "AnimationWalkRight.h"

// CONSTRUCTOR TEMPORAL
PlayerGraphic::PlayerGraphic(AssetsLoader& assets):
                    assets(assets), animation(assets.getTexture(0), 5, 5, 5, 5), x(5), y(5) {
    animation.loadRects(PLAYER_IDLE_ANIMATION_FRAMES, PLAYER_ANIMATION_X,
    PLAYER_IDLE_ANIMATION_Y, PLAYER_ANIMATION_WIDTH, PLAYER_ANIMATION_HEIGHT);
}

void PlayerGraphic::render(int frame){
    animation.render(frame);
}

void PlayerGraphic::moveUp(int distance) {
    animation = Animation(assets.getTexture(0), x, y, x, y - distance);
    animation.loadRects(PLAYER_WALK_Y_ANIMATION_FRAMES, PLAYER_ANIMATION_X,
    PLAYER_WALK_Y_UP_ANIMATION_Y, PLAYER_ANIMATION_WIDTH, PLAYER_ANIMATION_HEIGHT);
    y -= distance;
}

void PlayerGraphic::moveDown(int distance) {
    animation = Animation(assets.getTexture(0), x, y, x, y + distance);
    animation.loadRects(PLAYER_WALK_Y_ANIMATION_FRAMES, PLAYER_ANIMATION_X,
    PLAYER_WALK_Y_DOWN_ANIMATION_Y, PLAYER_ANIMATION_WIDTH, PLAYER_ANIMATION_HEIGHT);
    y += distance;
}

void PlayerGraphic::moveRight(int distance){
    animation = Animation(assets.getTexture(0), x, y, x + distance, y);
    animation.loadRects(PLAYER_WALK_X_ANIMATION_FRAMES, PLAYER_ANIMATION_X,
    PLAYER_WALK_RIGHT_ANIMATION_Y, PLAYER_ANIMATION_WIDTH, PLAYER_ANIMATION_HEIGHT);
    x += distance;
}

void PlayerGraphic::moveLeft(int distance){
    animation = Animation(assets.getTexture(0), x, y, x - distance, y);
    animation.loadRects(PLAYER_WALK_X_ANIMATION_FRAMES, PLAYER_ANIMATION_X,
    PLAYER_WALK_LEFT_ANIMATION_Y, PLAYER_ANIMATION_WIDTH, PLAYER_ANIMATION_HEIGHT);
    x -= distance;
}

void PlayerGraphic::idle(){
    animation = Animation(assets.getTexture(0), x, y, x, y);
    animation.loadRects(PLAYER_IDLE_ANIMATION_FRAMES, PLAYER_ANIMATION_X,
    PLAYER_IDLE_ANIMATION_Y, PLAYER_ANIMATION_WIDTH, PLAYER_ANIMATION_HEIGHT);
}