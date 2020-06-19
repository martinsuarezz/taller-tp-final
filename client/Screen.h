#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "SDL2/SDL.h"
#include <string>

class Renderer;

class MapGraphic;

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

        // Obtener las posiciones de la camara
        int getPositionX() const;
        int getPositionY() const;
        // Obtener dimensiones de la camara
        int getWidth() const;
        int getHeight() const;

        //Render the screen.
        void render();
};


#endif
