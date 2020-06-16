#include "PlayerGraphic.h"
#include "AssetsLoader.h"
#include "Screen.h"


// CONSTRUCTOR TEMPORAL
PlayerGraphic::PlayerGraphic(AssetsLoader& assets):
                    assets(assets), animation(assets.getTexture("player_sprite"), 5, 5, 5, 5), x(5), y(5) {
    animation.loadRects(PLAYER_IDLE_ANIMATION_FRAMES, PLAYER_ANIMATION_X,
    PLAYER_IDLE_ANIMATION_Y, PLAYER_ANIMATION_WIDTH, PLAYER_ANIMATION_HEIGHT);
}

void PlayerGraphic::render(int frame, Screen& background){
    animation.render(frame, x, y, background);
}

void PlayerGraphic::moveUp(int distance) {
    std::string soundName = "walking_sound";
    assets.getSound(soundName).play(1);
    std::string textureName = "player_sprite";
    animation = Animation(assets.getTexture(textureName), x, y, x, y - distance);
    animation.loadRects(PLAYER_WALK_Y_ANIMATION_FRAMES, PLAYER_ANIMATION_X,
    PLAYER_WALK_Y_UP_ANIMATION_Y, PLAYER_ANIMATION_WIDTH, PLAYER_ANIMATION_HEIGHT);
}

void PlayerGraphic::moveDown(int distance) {
    std::string soundName = "walking_sound";
    assets.getSound(soundName).play(1);
    std::string textureName = "player_sprite";
    animation = Animation(assets.getTexture(textureName), x, y, x, y + distance);
    animation.loadRects(PLAYER_WALK_Y_ANIMATION_FRAMES, PLAYER_ANIMATION_X,
    PLAYER_WALK_Y_DOWN_ANIMATION_Y, PLAYER_ANIMATION_WIDTH, PLAYER_ANIMATION_HEIGHT);
}

void PlayerGraphic::moveRight(int distance){
    std::string soundName = "walking_sound";
    assets.getSound(soundName).play(1);
    std::string textureName = "player_sprite";
    animation = Animation(assets.getTexture(textureName), x, y, x + distance, y);
    animation.loadRects(PLAYER_WALK_X_ANIMATION_FRAMES, PLAYER_ANIMATION_X,
    PLAYER_WALK_RIGHT_ANIMATION_Y, PLAYER_ANIMATION_WIDTH, PLAYER_ANIMATION_HEIGHT);
}

void PlayerGraphic::moveLeft(int distance){
    std::string soundName = "walking_sound";
    assets.getSound(soundName).play(1);
    std::string textureName = "player_sprite";
    animation = Animation(assets.getTexture(textureName), x, y, x - distance, y);
    animation.loadRects(PLAYER_WALK_X_ANIMATION_FRAMES, PLAYER_ANIMATION_X,
    PLAYER_WALK_LEFT_ANIMATION_Y, PLAYER_ANIMATION_WIDTH, PLAYER_ANIMATION_HEIGHT);
}

void PlayerGraphic::idle(){
    std::string textureName = "player_sprite";
    animation = Animation(assets.getTexture(textureName), x, y, x, y);
    animation.loadRects(PLAYER_IDLE_ANIMATION_FRAMES, PLAYER_ANIMATION_X,
    PLAYER_IDLE_ANIMATION_Y, PLAYER_ANIMATION_WIDTH, PLAYER_ANIMATION_HEIGHT);
}

int PlayerGraphic::getX(){
    return x;
}

int PlayerGraphic::getY(){
    return y;
}