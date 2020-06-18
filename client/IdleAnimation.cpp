#include "IdleAnimation.h"
#include "PlayerGraphic.h"
#include "Screen.h"
#include "Sound.h"
#include <iostream>

#define WALKING_ANIMATION_DURATION 1000
#define IDLE_ANIMATION_FRAMES 1

//WalkingAnimation::WalkingAnimation(PlayerGraphic& player, int direction, int distance):Animation(player, direction, distance){}

IdleAnimation::IdleAnimation(PlayerGraphic& player): Animation(player, 0, 0){
    targetMiliseconds = WALKING_ANIMATION_DURATION / IDLE_ANIMATION_FRAMES;
    int animation_y = 10;
    int animation_x = 0;
    int animation_w = 25;
    int animation_h = 45;
    for(int i = 0; i < IDLE_ANIMATION_FRAMES; i++) {
        SDL_Rect area;
        area.y = animation_y;
        area.x = animation_x + i * animation_w;
        area.w = animation_w;
        area.h = animation_h;
        areas.push_back(area);
    }

}

void IdleAnimation::moveUp(){
    player.getSound().play(1);
    player.updateAnimation(new WalkingAnimation(player, 0, 64));
}

void IdleAnimation::moveRight(){
    player.getSound().play(1);
    player.updateAnimation(new WalkingAnimation(player, 1, 64));
}

void IdleAnimation::moveDown(){
    player.getSound().play(1);
    player.updateAnimation(new WalkingAnimation(player, 2, 64));
}

void IdleAnimation::moveLeft(){
    player.getSound().play(1);
    player.updateAnimation(new WalkingAnimation(player, 3, 64));
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