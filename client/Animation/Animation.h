#ifndef ANIMATION_H
#define ANIMATION_H
#include <vector>
#include <string>
#include <SDL2/SDL.h>

class Texture;

class Sound;

// Clase que modela una animación.

class Animation{
    protected:
        Texture& texture;
        std::vector<SDL_Rect>& frames;
        int ammountFrames;
        int frameDuration;
        int elapsedMicroseconds;
        int targetMicroseconds;
        int currentFrame;

    public:
        // Recibe la textura a animar, un vector con los frames de animación,
        // y la duración de la animación.
        Animation(Texture& texture, std::vector<SDL_Rect>& frames, 
                    int duration);

        // Renderiza la animación en la posición indicada (pixeles absolutos)
        void render(int x, int y, int timeElapsed);

        Animation(Animation&&);

        ~Animation();
};

#endif
