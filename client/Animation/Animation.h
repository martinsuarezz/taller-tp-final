#ifndef ANIMATION_H
#define ANIMATION_H
#include <vector>
#include <string>
#include <SDL2/SDL.h>

class Texture;

class Animation{
    protected:
        Texture& texture;
        std::vector<SDL_Rect>& frames;
        int duration;
        int x;
        int y;
        int elapsedMiliseconds;
        int targetMiliseconds;
        int currentAnimation;
        int ammountFrames;
        int remainingFrames;

    public:
        Animation(Texture& texture, std::vector<SDL_Rect>& frames, int duration);
        void render(int x, int y);
        ~Animation();
};

#endif
