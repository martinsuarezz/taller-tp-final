#ifndef MAP_GRAPHIC_H
#define MAP_GRAPHIC_H
#include <string>
#include <vector>
#include "MapGraphic.h"
#include <SDL2/SDL.h>

class AssetsLoader;

class MapGraphic{
    private:
        std::vector<int> tiles;
        std::vector<int> layer0;
        std::vector<int> layer1;
        std::vector<int> layer2;
        AssetsLoader& assets;
        int width;
        int height;
        void renderLayer(int x, int y, SDL_Rect* area, int layer);

    public:
        MapGraphic(std::string mapFile, AssetsLoader& assets);
        void render(int x, int y, SDL_Rect* area);
        int getTile(int x, int y, int layer) const; 
        int getPixelsWidth() const;
        int getPixelsHeight() const;
};

#endif
