/*

#ifndef WALKING_ANIMATION_H
#define WALKING_ANIMATION_H
#include <vector>
#include <SDL2/SDL.h>
#include <string>
#include "Animation.h"

class Screen;

class PlayerGraphic;

class AssetsLoader;

class WalkingAnimation: public Animation{
    private:
        std::string direction;
        int distance;
        void updatePosition();

    public:
        WalkingAnimation(PlayerGraphic& player, AssetsLoader& assets, std::string direction, int distance);
        void moveUp();
        void moveRight();
        void moveDown();
        void moveLeft();

};

#endif

*/