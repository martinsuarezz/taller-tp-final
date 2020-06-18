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
/*
class WalkingAnimation{
    private:
        PlayerGraphic& player;
        int elapsedMiliseconds;
        int targetMiliseconds;
        int currentFrame;
        int distance;
        int direction;
        std::vector<SDL_Rect> areas;

    public:
        WalkingAnimation(PlayerGraphic& player, int direction, int distance);
        void updatePosition();
        void render(Screen& screen);

};
*/

#endif
