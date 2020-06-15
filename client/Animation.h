#ifndef ANIMATION_H
#define ANIMATION_H
#include <vector>
#include <SDL2/SDL.h>

class Screen;

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
        void render(int frame, Screen& background);
        void loadRects(int frames, int animation_x, int animation_y,
                        int animation_w, int animation_h);
        Animation& operator=(Animation&& other);
        
        ~Animation();
};

#endif
