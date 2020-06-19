#include "IdleAnimation.h"
#include "PlayerGraphic.h"
#include "Screen.h"
#include "Sound.h"
#include "Configuration.h"
#include "AssetsLoader.h"
#include <iostream>

IdleAnimation::IdleAnimation(PlayerGraphic& player, AssetsLoader& assets): Animation(player, assets){
    Configuration& config = Configuration::getInstance();
    duration = config.getValue("idle_animation_duration");
    animationFrames = config.getValue("idle_animation_frames");
    targetMiliseconds = duration / animationFrames;
    elapsedMiliseconds = 0;
    currentAnimation = 0;
    remainingFrames = (duration * config.getValue("fps")) / 1000;
    animationName = "idle_animation";
}

void IdleAnimation::moveUp(){
    player.getSound().play(1);
    player.updateAnimation(new WalkingAnimation(player, assets, "up", 64));
}

void IdleAnimation::moveRight(){
    player.getSound().play(1);
    player.updateAnimation(new WalkingAnimation(player, assets, "right", 64));
}

void IdleAnimation::moveDown(){
    player.getSound().play(1);
    player.updateAnimation(new WalkingAnimation(player, assets, "down", 64));
}

void IdleAnimation::moveLeft(){
    player.getSound().play(1);
    player.updateAnimation(new WalkingAnimation(player, assets, "left", 64));
}

void IdleAnimation::updatePosition(){
    return;
}
