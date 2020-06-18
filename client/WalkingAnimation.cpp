#include "WalkingAnimation.h"
#include "PlayerGraphic.h"
#include "Configuration.h"
#include "Screen.h"
#include <iostream>

WalkingAnimation::WalkingAnimation(PlayerGraphic& player, int direction, int distance): Animation(player, direction, distance){
    Configuration& config = Configuration::getInstance();
    duration = config.getValue("walking_animation_duration");
    animationFrames = config.getValue("walking_animation_frames");
    targetMiliseconds = duration / animationFrames;
    elapsedMiliseconds = 0;
    currentAnimation = 0;
    remainingFrames = (duration * config.getValue("fps")) / 1000;
    int animation_y = 145;
    int animation_x = 0;
    int animation_w = 25;
    int animation_h = 45;
    for(int i = 0; i < animationFrames; i++) {
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
