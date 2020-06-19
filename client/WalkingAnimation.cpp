#include "WalkingAnimation.h"
#include "PlayerGraphic.h"
#include "Configuration.h"
#include "Screen.h"
#include "AssetsLoader.h"
#include <iostream>

WalkingAnimation::WalkingAnimation(PlayerGraphic& player, AssetsLoader& assets, std::string direction, int distance): Animation(player, assets), direction(direction), distance(distance){
    Configuration& config = Configuration::getInstance();
    duration = config.getValue("walking_animation_duration");
    animationFrames = config.getValue("walking_animation_frames");
    targetMiliseconds = duration / animationFrames;
    elapsedMiliseconds = 0;
    currentAnimation = 0;
    remainingFrames = (duration * config.getValue("fps")) / 1000;
    animationName = "walking_animation_" + direction;
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

void WalkingAnimation::updatePosition(){
    if (remainingFrames <= 0)
        return;
    int pixelsToMove = (int) nearbyint((double)distance / (double)remainingFrames);
    if (direction == "up")
        player.addY(-pixelsToMove);
    else if (direction == "right")
        player.addX(pixelsToMove);
    else if (direction == "down")
        player.addY(pixelsToMove);
    else if (direction == "left")
        player.addX(-pixelsToMove);
    else
        std::cout << "Advertencia: dirección de movimiento errónea." << std::endl;
    

    distance -= pixelsToMove;
}