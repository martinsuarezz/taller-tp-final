#ifndef SDL_HANDLER_H
#define SDL_HANDLER_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#define AUDIO SDL_INIT_AUDIO
#define VIDEO SDL_INIT_VIDEO
#define TIMER SDL_INIT_TIMER
#define EVENTS SDL_INIT_EVENTS

// Clase para inicializar los módulos de SDL.

class SDLHandler{
    private:
        bool mixerWasInitialized;

    public:
        SDLHandler(Uint32 flags);

        // Inicializa el módulo de imágenes.
        void initializeImage();

        // Inicializa el módulo de fuentes.
        void initializeTTF();

        // Incializa el módulo de sonido.
        void initializeMixer(int frequency = MIX_DEFAULT_FREQUENCY, 
                            int channels = 2, 
                            Uint16 format = MIX_DEFAULT_FORMAT, 
                            int chunksize = 1024);

        // Se le agregan flags a SDL.
        void setHint(const char* name, const char* value);
        ~SDLHandler();
};

#endif
