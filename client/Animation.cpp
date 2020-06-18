#include "Animation.h"
#include "Texture.h"
#include "Screen.h"
#include "Configuration.h"
#include <math.h>
#include <iostream>
#include <stdexcept>
#include "PlayerGraphic.h"

#define WALKING_ANIMATION_DURATION 1000
#define WALKING_ANIMATION_FRAMES 5

Animation::Animation(PlayerGraphic& player, int direction, int distance): player(player), distance(distance), duration(WALKING_ANIMATION_DURATION), direction(direction){
    Configuration& config = Configuration::getInstance();
    
    elapsedMiliseconds = 0;
    currentFrame = 0;
    remainingFrames = duration * config.getValue("fps") / 1000;

    /*targetMiliseconds = WALKING_ANIMATION_DURATION / WALKING_ANIMATION_FRAMES;
    int animation_y = 10;
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
    }*/
}

void Animation::updatePosition(){
    if (remainingFrames <= 0)
        return;
    int pixelsToMove = (int) nearbyint((double)distance / (double)remainingFrames);
    //std::cout << "Pixels to move: " << pixelsToMove << std::endl;
    switch(direction){
        case 0:
            player.addY(-pixelsToMove);
            break;
        case 1:
            player.addX(pixelsToMove);
            break;
        case 2:
            player.addY(pixelsToMove);
            break;
        case 3:
            player.addX(-pixelsToMove);
            break;
    }
    distance -= pixelsToMove;
}

void Animation::render(Screen& screen){
    Texture& body = player.getBodyAsset();
    Configuration& config = Configuration::getInstance();
    int milisecondsPerFrame = 1000 / config.getValue("fps");
    if (elapsedMiliseconds <= targetMiliseconds && (elapsedMiliseconds += milisecondsPerFrame) >= targetMiliseconds){
        currentFrame++;
        targetMiliseconds += WALKING_ANIMATION_DURATION / WALKING_ANIMATION_FRAMES;
    }
    /*
    if ((size_t)currentFrame >= areas.size())
        throw std::runtime_error("Error al renderizar animación");
    */
    //std::cout << "X, Y: " << player.getX() << "," << player.getY() << std::endl;
    this->updatePosition();
    body.render(player.getX() - screen.getPositionX(), player.getY() - screen.getPositionY(), &areas[currentFrame % areas.size()]);
    remainingFrames--;
    if (remainingFrames <= 0)
        player.idle();
}

Animation::~Animation(){

}