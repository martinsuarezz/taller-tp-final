#ifndef MAP_GRAPHIC_H
#define MAP_GRAPHIC_H
#include <string>
#include <vector>
#include "MapGraphic.h"
#include <SDL2/SDL.h>

class AssetsLoader;

// Clase que modela el mapa en la interfaz gráfica.

class MapGraphic{
    private:
        std::vector<int> layer0;
        std::vector<int> layer1;
        std::vector<int> layer2;
        AssetsLoader& assets;
        int width;
        int height;
        void renderLayer(int x, int y, SDL_Rect* area, int layer);
        int getTile(int x, int y, int layer) const; 

    public:
        MapGraphic(std::string mapFile, AssetsLoader& assets);

        // Renderiza el mapa en las posiciones recibidas y con 
        // el área determinada.
        void render(int x, int y, SDL_Rect* area);

        // Obtiene las dimensiones totales del mapa en píxeles.
        int getPixelsWidth() const;
        int getPixelsHeight() const;
};

#endif
