#include "Animation.h"
#include "Texture.h"
#include "Screen.h"
#include "Configuration.h"
#include <math.h>
#include <iostream>
#include <stdexcept>
#include "PlayerGraphic.h"

Animation::Animation(PlayerGraphic& player, int direction, int distance): player(player), distance(distance), direction(direction){}

void Animation::updatePosition(){
    if (remainingFrames <= 0)
        return;
    int pixelsToMove = (int) nearbyint((double)distance / (double)remainingFrames);
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
        currentAnimation++;
        targetMiliseconds += duration / animationFrames;
    }
    /*
    if ((size_t)currentFrame >= areas.size())
        throw std::runtime_error("Error al renderizar animación");
    */
    //std::cout << "X, Y: " << player.getX() << "," << player.getY() << std::endl;
    this->updatePosition();
    body.render(player.getX() - screen.getPositionX(), player.getY() - screen.getPositionY(), &areas[currentAnimation % areas.size()]);
    remainingFrames--;
    if (remainingFrames <= 0)
        player.idle();
}

Animation::~Animation(){

}