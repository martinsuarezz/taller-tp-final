/*

#ifndef IDLE_ANIMATION_H
#define IDLE_ANIMATION_H
#include <vector>
#include <SDL2/SDL.h>
#include "Animation.h"

class Screen;

class PlayerGraphic;

class AssetsLoader;

class IdleAnimation: public Animation{
    private:
        void updatePosition();
        
    public:
        IdleAnimation(PlayerGraphic& player, AssetsLoader& assets);
        void moveUp();
        void moveRight();
        void moveDown();
        void moveLeft();

};

#endif

*/
