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
        std::vector<int> itemLayer;
        AssetsLoader& assets;
        int width;
        int height;
        void renderLayer(int x, int y, SDL_Rect* area, int layer);
        void renderTile(int i, int j, int x, int y, int layer);
        void renderItem(int i, int j, int x, int y);
        int getTile(int x, int y, int layer) const; 

    public:
        MapGraphic(std::string mapFile, AssetsLoader& assets);

        // Renderiza el mapa en las posiciones recibidas y con 
        // el área determinada.
        void render(int x, int y, SDL_Rect* area);

        // Obtiene las dimensiones totales del mapa en píxeles.
        int getPixelsWidth() const;
        int getPixelsHeight() const;

        // Remueve el item en la posición dada
        void removeItem(int x, int y);

        // Agrega un item en la posición dada.
        void addItem(int x, int y, int itemId);

        // Obtiene las coordenadas del mapa correspondientes
        // al respectivo par (x, y) de píxeles.
        std::pair<int, int> getCoordinates(int x, int y, SDL_Rect* area);
};

#endif
