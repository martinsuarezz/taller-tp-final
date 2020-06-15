#ifndef ANIMATION_H
#define ANIMATION_H
#include <vector>
#include <SDL2/SDL.h>

class Texture;

class Animation{
    protected:
        Texture& texture;
        std::vector<SDL_Rect> areas;
        int xInitial;
        int yInitial;
        int xFinal;
        int yFinal;

    public:
        Animation(Texture& texture, int xInitial, int yInitial, 
                        int xFinal, int yFinal);
        Animation(Animation&& other);
        void render(int frame);
        Animation& operator=(Animation&& other);
        ~Animation();
};

#endif
