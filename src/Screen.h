#ifndef SCREEN_H
#define SCREEN_H

#include "SDL2/SDL.h"
#include <string>

class Renderer;

class MapGraphic;

class Entity;

class EntityContainer;

// Clase que modela la pantalla.

class Screen {
    private:
        MapGraphic& map;
        Renderer& renderer;
        SDL_Rect camera;
        
        // Devolver valores de x e y dentro de los parametros de la ventana.
        int checkBoundryX(int x) const;
        int checkBoundryY(int y) const;

    public:
        // Crear la camara con el mapa de fondo.
        Screen(MapGraphic& map, Renderer& renderer, 
                int screen_w, int screen_h);
        // Liberar recursos
        ~Screen();

        // Actualiza la camara al renderer actual (usar si hubo cambio de viewport)
        void updateCamera();

        // Setea el tamaño de la camara.
        void setScreenSize(int width, int height);
        // Setea la posición de la camara.
        void setPosition(int x, int y);
        // Mueve la camara.
        void movePosition(int x, int y);
        // Mueve la camara al centro de la imagen.
        void moveToCenter();
        // Mueve la camara para que las posiciones dadas estén en el centro.
        void centerToPosition(int x, int y);
        // Centra la cámara a la posición del jugador.
        void centerToPlayerPosition(EntityContainer& entities);

        // Obtener las posiciones de la cámara
        int getPositionX() const;
        int getPositionY() const;
        // Obtener dimensiones de la cámara
        int getWidth() const;
        int getHeight() const;

        // Devuelve si la entidad está dentro de la cámara
        bool isInbound(const Entity& entity) const;

        //Render the screen.
        void render();

        std::pair<int, int> getMapCoordinates(int x, int y);
};


#endif
