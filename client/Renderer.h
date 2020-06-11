#ifndef RENDERER_H
#define RENDERER_H
#include <SDL2/SDL.h>
#include <string>

class Window;

// Objeto que abstrae a SDL_Renderer.
class Renderer{
    private:
        SDL_Renderer* renderer;

    public:
        Renderer();
        Renderer(SDL_Window* window);

        ~Renderer();

        // Devuelve el puntero al renderer de SDL.
        SDL_Renderer* getSDLRenderer() const;

        // Establece el color con el que dibujar.
        void setDrawColor(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha);

        // Renderiza los últimos cambios.
        void renderPresent() const;

        // Limpia la pantalla.
        void clear() const;

        // Asignación por movimiento.
        Renderer& operator=(Renderer&&);

        // Elimino el operador asignación por copia.
        Renderer& operator=(const Renderer&) = delete;
        
        // Pasaje copia
        Renderer(Renderer&&);
};

#endif
