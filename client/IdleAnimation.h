#ifndef IDLE_ANIMATION_H
#define IDLE_ANIMATION_H
#include <vector>
#include <SDL2/SDL.h>
#include "Animation.h"

class Screen;

class PlayerGraphic;

class IdleAnimation: public Animation{
    public:
        IdleAnimation(PlayerGraphic& player);
        void moveUp();
        void moveRight();
        void moveDown();
        void moveLeft();

};

#endif
