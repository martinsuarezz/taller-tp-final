#ifndef WALKING_ANIMATION_H
#define WALKING_ANIMATION_H
#include <vector>
#include <SDL2/SDL.h>
#include "Animation.h"

class Screen;

class PlayerGraphic;

class WalkingAnimation: public Animation{
    public:
        WalkingAnimation(PlayerGraphic& player, int direction, int distance);
        void moveUp();
        void moveRight();
        void moveDown();
        void moveLeft();

};

#endif
