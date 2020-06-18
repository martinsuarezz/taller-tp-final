#ifndef ANIMATION_H
#define ANIMATION_H
#include <vector>
#include <SDL2/SDL.h>

class PlayerGraphic;

class Screen;

class Animation{
    protected:
        PlayerGraphic& player;
        int elapsedMiliseconds;
        int targetMiliseconds;
        int currentFrame;
        int remainingFrames;
        int distance;
        int duration;
        int direction;
        std::vector<SDL_Rect> areas;
        void updatePosition();

    public:
        Animation(PlayerGraphic& player, int direction, int distance);
        void render(Screen& screen);
        virtual void moveUp() = 0;
        virtual void moveRight() = 0;
        virtual void moveDown() = 0;
        virtual void moveLeft() = 0;
        ~Animation();
};

#endif
