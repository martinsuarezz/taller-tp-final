#include "AssetsLoader.h"
#include "MapGraphic.h"
#include "Configuration.h"
#include "Constants.h"
#include "nlohmann/json.hpp"
#include <vector>
#include <fstream>

using json = nlohmann::json;

MapGraphic::MapGraphic(std::string mapFile, AssetsLoader& assets):
                        assets(assets), width(0), height(0){
    std::ifstream file(std::string("maps/" + mapFile));
    json mapJSON;
    file >> mapJSON;

    width = mapJSON["width"];
    height = mapJSON["height"];

    json layers = mapJSON["layers"];
    layer0 = layers[0]["data"].get<std::vector<int>>();
    layer1 = layers[1]["data"].get<std::vector<int>>();
    layer2 = layers[2]["data"].get<std::vector<int>>();
    itemLayer = std::vector<int>(width * height, 0);
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
        case ITEM_LAYER:
            tile = itemLayer[x + y * width];
            break;
    }
    return tile;
}

std::pair<int, int> MapGraphic::getCoordinates(int x, int y, SDL_Rect* area){
    Configuration& config = Configuration::getInstance();
    
    int tileSize = config.getValue("tile_size");
    int xTile = (x + area->x) / tileSize;
    int yTile = (y + area->y) / tileSize;
    return std::pair<int, int>(xTile, yTile);
}

void MapGraphic::renderTile(int i, int j, int x, int y, int layer){
    int tileId = getTile(i, j, layer);
    if (tileId == 0)
        return;
    try{
        assets.getTexture(std::to_string(tileId)).render(x, y); 
    }
    catch (std::out_of_range& e){}
}

void MapGraphic::renderItem(int i, int j, int x, int y){
    Configuration& config = Configuration::getInstance();
    int itemId = getTile(i, j, ITEM_LAYER);
    int xTrue = x + config.getValue("item_render_offset_x");
    int yTrue = y + config.getValue("item_render_offset_y");
    if (itemId == 0)
        return;
    try{
        assets.getTexture("item" + 
                        std::to_string(itemId) + "_icon").render(xTrue, yTrue);
    }
    catch (std::out_of_range& e){}
}

void MapGraphic::renderLayer(int xScreen, int yScreen, 
                            SDL_Rect* area, int layer){
                                
    Configuration& config = Configuration::getInstance();
    int tileSize = config.getValue("tile_size");
    int offsetRender = tileSize * config.getValue("map_render_offset_tiles");

    xScreen -= offsetRender;
    yScreen -= offsetRender;

    int xInitial = area->x - offsetRender;
    int yInitial = area->y - offsetRender;

    int xFinal = roundUp(area->x + area->w, tileSize);
    int yFinal = roundUp(area->y + area->h, tileSize);

    int xCurrent = xScreen - (xInitial - roundDown(xInitial, tileSize));
    int yCurrent = yScreen - (yInitial - roundDown(yInitial, tileSize));

    for (int j = roundDown(yInitial, tileSize) / tileSize; 
            yCurrent < yFinal; yCurrent += tileSize, j++){

        for (int i = roundDown(xInitial, tileSize) / tileSize;
                xCurrent < xFinal; xCurrent += tileSize, i++){

            if (layer == ITEM_LAYER)
                renderItem(i, j, xCurrent, yCurrent);
            else
                renderTile(i, j, xCurrent, yCurrent, layer);
        }

        xCurrent = xScreen - (xInitial - roundDown(xInitial, tileSize));
        
    }
    
}

void MapGraphic::render(int xScreen, int yScreen, SDL_Rect* area){
    for (int i = 0; i < 4; i++){
        renderLayer(xScreen, yScreen, area, i);
    }
}

void MapGraphic::removeItem(int x, int y){
    itemLayer[y * width + x] = 0;
}

void MapGraphic::addItem(int x, int y, int itemId){
    itemLayer[y * width + x] = itemId;
}

int MapGraphic::getPixelsWidth() const{
    Configuration& config = Configuration::getInstance();
    return width * config.getValue("tile_size");
}

int MapGraphic::getPixelsHeight() const{
    Configuration& config = Configuration::getInstance();
    return height * config.getValue("tile_size");
}
