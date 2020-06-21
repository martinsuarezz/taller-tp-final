#include "Screen.h"
#include "MapGraphic.h"
#include "Renderer.h"
#include "Entity.h"
#include "Configuration.h"

Screen::Screen(MapGraphic& map, Renderer& renderer, 
int screen_w, int screen_h): map(map), renderer(renderer) {
    camera = {0, 0, renderer.getWidth(), renderer.getHeight()};
}

Screen::~Screen() {}

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

//CUIDADO -> POSIBLE BUG -> PANTALLA MAS GRANDE QUE IMAGEN
//-> INVESTIGAR -> SE AGREGA LOGICA O SE MANEJA SOLO -> SE ROMPE EL CHECKBOUNDRY ?
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
    int entityX = entity.getX();
    int entityY = entity.getY();
    bool inboundX = (entityX > camera.x - tileSize) && (entityX < camera.x + camera.w + tileSize);
    bool inboundY = (entityY > camera.y - tileSize) && (entityY < camera.y + camera.h + tileSize);

    return inboundX && inboundY;
}
