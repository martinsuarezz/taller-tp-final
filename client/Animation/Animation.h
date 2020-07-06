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
        int duration;
        int x;
        int y;
        int elapsedMiliseconds;
        int targetMiliseconds;
        int currentAnimation;
        int ammountFrames;
        int remainingFrames;

    public:
        // Recibe la textura a animar, un vector con los frames de animación,
        // y la duración de cada frame.
        Animation(Texture& texture, std::vector<SDL_Rect>& frames, 
                    int duration);

        // Renderiza la animación en la posición indicada (pixeles absolutos)
        void render(int x, int y);

        ~Animation();
};

#endif
