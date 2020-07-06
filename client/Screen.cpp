#include "Screen.h"
#include "MapGraphic.h"
#include "Renderer.h"
#include "Entity.h"
#include "EntityContainer.h"
#include "Configuration.h"
#include <stdexcept>

Screen::Screen(MapGraphic& map, Renderer& renderer, 
                int screen_w, int screen_h): map(map), renderer(renderer){
    camera = {0, 0, renderer.getWidth(), renderer.getHeight()};
}

Screen::~Screen() {}

void Screen::updateCamera(){
    camera = {0, 0, renderer.getWidth(), renderer.getHeight()};
}

int Screen::checkBoundryX(int x) const {
    if (x < 0)
        return 0;
    if (x + camera.w > map.getPixelsWidth())
        return map.getPixelsWidth() - camera.w;
    return x;
}

int Screen::checkBoundryY(int y) const {
    if (y < 0)
        return 0;
    if (y + camera.h > map.getPixelsHeight())
        return map.getPixelsHeight() - camera.h;
    return y;
}

void Screen::setScreenSize(int width, int heigh) {
    camera.w = width;
    camera.h = heigh;
}

void Screen::setPosition(int x, int y) {
    camera.x = checkBoundryX(x);
    camera.y = checkBoundryY(y);
}

void Screen::movePosition(int x, int y) {
    camera.x = checkBoundryX(camera.x + x);
    camera.y = checkBoundryY(camera.y + y);
}

void Screen::moveToCenter() {
    camera.x = checkBoundryX((map.getPixelsWidth() / 2) - camera.w / 2);
    camera.y = checkBoundryY((map.getPixelsHeight() / 2) - camera.h / 2);
}

void Screen::centerToPosition(int x, int y){
    this->setPosition(x - camera.w / 2, y - camera.h / 2);
}

void Screen::centerToPlayerPosition(EntityContainer& entities){
    try{
        Entity& player = entities.getPlayer();
        centerToPosition(player.getPixelsX(), player.getPixelsY());
    }
    catch (std::runtime_error& e){
        centerToPosition(0, 0);
    }
}

int Screen::getPositionX() const {
    return camera.x;
}

int Screen::getPositionY() const {
    return camera.y;
}

int Screen::getWidth() const {
    return camera.w;
}

int Screen::getHeight() const {
    return camera.h;
}

void Screen::render() {
    map.render(0, 0, &camera);
}

bool Screen::isInbound(const Entity& entity) const{
    Configuration& config = Configuration::getInstance();
    int tileSize = config.getValue("tile_size");
    int entityX = entity.getPixelsX();
    int entityY = entity.getPixelsY();
    bool inboundX = (entityX > camera.x - tileSize) && 
                    (entityX < camera.x + camera.w + tileSize);
    bool inboundY = (entityY > camera.y - tileSize) && 
                    (entityY < camera.y + camera.h + tileSize);

    return inboundX && inboundY;
}
