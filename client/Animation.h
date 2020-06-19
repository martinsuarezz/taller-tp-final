#ifndef ANIMATION_H
#define ANIMATION_H
#include <vector>
#include <string>
#include <SDL2/SDL.h>

class AssetsLoader;

class PlayerGraphic;

class Screen;

class Animation{
    protected:
        PlayerGraphic& player;
        AssetsLoader& assets;
        int elapsedMiliseconds;
        int targetMiliseconds;
        int currentAnimation;
        int animationFrames;
        int remainingFrames;
        int duration;
        std::string animationName;
        virtual void updatePosition() = 0;

    public:
        Animation(PlayerGraphic& player, AssetsLoader& assets);
        void render(Screen& screen);
        virtual void moveUp() = 0;
        virtual void moveRight() = 0;
        virtual void moveDown() = 0;
        virtual void moveLeft() = 0;
        ~Animation();
};

#endif
