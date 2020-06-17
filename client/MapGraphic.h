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
        AssetsLoader& assets;
        int height;
        int width;
        

    public:
        MapGraphic(std::string mapFile, AssetsLoader& assets, int height, int width);
        void render(int x, int y, SDL_Rect* area);
        int getTile(int x, int y);
};

#endif