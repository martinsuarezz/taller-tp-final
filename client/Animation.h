#ifndef ANIMATION_H
#define ANIMATION_H
#include <vector>
#include <SDL2/SDL.h>

class Texture;

class Animation{
    protected:
        Texture& texture;
        std::vector<SDL_Rect> areas;

    public:
        Animation(Texture& texture);
        Animation(Animation&& other);
        void render(int x, int y, int frame);

        Animation& operator=(Animation&& other);
};

#endif
