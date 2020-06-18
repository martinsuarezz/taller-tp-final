#include "IdleAnimation.h"
#include "PlayerGraphic.h"
#include "Screen.h"
#include "Sound.h"
#include "Configuration.h"
#include <iostream>

IdleAnimation::IdleAnimation(PlayerGraphic& player): Animation(player, 0, 0){
    Configuration& config = Configuration::getInstance();
    duration = config.getValue("idle_animation_duration");
    animationFrames = config.getValue("idle_animation_frames");
    targetMiliseconds = duration / animationFrames;
    elapsedMiliseconds = 0;
    currentAnimation = 0;
    remainingFrames = (duration * config.getValue("fps")) / 1000;
    int animation_y = 10;
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
