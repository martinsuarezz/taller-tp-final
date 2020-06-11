#ifndef WINDOW_H
#define WINDOW_H
#include <SDL2/SDL.h>
#include <string>
#include "Renderer.h"

// Esta clase modela una ventana en la cuál se dibujará
// la interfaz gráfica.

class Window{
    private:
        SDL_Window* window;
        Renderer renderer;
        int height;
        int width;

    public:
        Window(std::string name, int width, int height, 
                int x = SDL_WINDOWPOS_UNDEFINED, 
                int y = SDL_WINDOWPOS_UNDEFINED, 
                Uint32 flags = SDL_WINDOW_SHOWN);

        // Devuelve el objeto renderer asociado a la ventana.
        Renderer getRenderer();

        // Devuelve el puntero a la ventana de SDL.
        SDL_Window* getSDLWindow() const;
};

#endif
