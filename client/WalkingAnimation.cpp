#include "WalkingAnimation.h"
#include "PlayerGraphic.h"
#include "Screen.h"

#define WALKING_ANIMATION_DURATION 1000
#define FPS 60
#define WALKING_ANIMATION_FRAMES 5

//WalkingAnimation::WalkingAnimation(PlayerGraphic& player, int direction, int distance):Animation(player, direction, distance){}

WalkingAnimation::WalkingAnimation(PlayerGraphic& player, int direction, int distance): Animation(player, direction, distance){
    targetMiliseconds = WALKING_ANIMATION_DURATION / WALKING_ANIMATION_FRAMES;
    int animation_y = 145;
    int animation_x = 0;
    int animation_w = 25;
    int animation_h = 45;
    for(int i = 0; i < WALKING_ANIMATION_FRAMES; i++) {
        SDL_Rect area;
        area.y = animation_y;
        area.x = animation_x + i * animation_w;
        area.w = animation_w;
        area.h = animation_h;
        areas.push_back(area);
    }
}

void WalkingAnimation::moveUp(){
    return;
}

void WalkingAnimation::moveRight(){
    return;
}

void WalkingAnimation::moveLeft(){
    return;
}

void WalkingAnimation::moveDown(){
    return;
}
/*
void WalkingAnimation::updatePosition(){
    int pixelsToMove = distance / (WALKING_ANIMATION_FRAMES * FPS) / 1000;
    switch(direction){
        case 0:
            player.addX(-pixelsToMove);
            break;
        case 1:
            player.addY(pixelsToMove);
            break;
        case 2:
            player.addX(pixelsToMove);
            break;
        case 3:
            player.addY(-pixelsToMove);
            break;
    }
    distance -= pixelsToMove;
}

void WalkingAnimation::render(Screen& screen){
    Texture& body = player.getBodyAsset();
    int milisecondsPerFrame = 1000 / FPS;
    if (elapsedMiliseconds <= targetMiliseconds && (elapsedMiliseconds += milisecondsPerFrame) >= targetMiliseconds){
        currentFrame++;
        targetMiliseconds += WALKING_ANIMATION_DURATION / WALKING_ANIMATION_FRAMES;
    }
    this->updatePosition();
    body.render(player.getX(), player.getY(), &areas[currentFrame]);
    if (distance == 0)
        player.idle();
}
*/