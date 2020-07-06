#include "AssetsLoader.h"
#include "MapGraphic.h"
#include "Configuration.h"
#include "nlohmann/json.hpp"
#include <vector>
#include <iostream>
#include <fstream>

using json = nlohmann::json;
/*
MapGraphic::MapGraphic(std::string mapFile, AssetsLoader& assets, int width, int height): assets(assets), width(width), height(height){
    this->tiles = {1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1};
}
*/
MapGraphic::MapGraphic(std::string mapFile, AssetsLoader& assets): assets(assets), width(0), height(0){
    std::ifstream file(std::string("maps/" + mapFile));
    json mapJSON;
    file >> mapJSON;

    width = mapJSON["width"];
    height = mapJSON["height"];

    json layers = mapJSON["layers"];
    layer0 = layers[0]["data"].get<std::vector<int>>();
    layer1 = layers[1]["data"].get<std::vector<int>>();
    layer2 = layers[2]["data"].get<std::vector<int>>();
}

static int roundDown(int number, int roundTo){
    return (number / roundTo) * roundTo;
}

static int roundUp(int number, int roundTo){
    return roundDown(number, roundTo) + roundTo;
}

int MapGraphic::getTile(int x, int y, int layer) const{
    int tile = -1;
    if (x >= width || y >= height){
        return tile;
    }
    switch(layer){
        case 0:
            tile = layer0[x + y * width];
            break;
        case 1:
            tile = layer1[x + y * width];
            break;
        case 2:
            tile = layer2[x + y * width];
            break;
    }
    return tile;
}

void MapGraphic::renderLayer(int xScreen, int yScreen, SDL_Rect* area, int layer){
    Configuration& config = Configuration::getInstance();
    int tileSize = config.getValue("tile_size");

    int xInitial = area->x;
    int yInitial = area->y;

    int xFinal = roundUp(area->x + area->w, tileSize);
    int yFinal = roundUp(area->y + area->h, tileSize);

    int xCurrent = xScreen - (xInitial - roundDown(xInitial, tileSize));
    int yCurrent = yScreen - (yInitial - roundDown(yInitial, tileSize));

    for (int j = roundDown(yInitial, tileSize) / tileSize; yCurrent < yFinal; yCurrent += tileSize, j++){
        for (int i = roundDown(xInitial, tileSize) / tileSize; xCurrent < xFinal; xCurrent += tileSize, i++){ 
            int tileId = getTile(i, j, layer);
            if (tileId == 0)
                continue;
            try{
                assets.getTexture(std::to_string(tileId)).render(xCurrent, yCurrent); 
            }
            catch (std::out_of_range& e){}
             
        }
        xCurrent = xScreen - (xInitial - roundDown(xInitial, tileSize));
    }

}

void MapGraphic::render(int xScreen, int yScreen, SDL_Rect* area){
    for (int i = 0; i < 3; i++){
        renderLayer(xScreen, yScreen, area, i);
    }
}

int MapGraphic::getPixelsWidth() const{
    Configuration& config = Configuration::getInstance();
    return width * config.getValue("tile_size");
}

int MapGraphic::getPixelsHeight() const{
    Configuration& config = Configuration::getInstance();
    return height * config.getValue("tile_size");
}