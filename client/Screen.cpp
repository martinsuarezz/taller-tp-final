#include "Screen.h"

Screen::Screen(const std::string & path, Renderer & renderer, 
int screen_w, int screen_h) : background(renderer) {
    //Load the file.
    background.loadFromFile(path, false);
    //Set the Screen position and size.
    camera = {0, 0, screen_w, screen_h};
}

Screen::~Screen() {}

int Screen::checkBoundryX(int x) const {
    if (x > background.getWidth() - camera.w) {
        return background.getWidth() - camera.w;
    } else if (x < 0) {
        return 0;
    } else {
        return x;
    }
}

int Screen::checkBoundryY(int y) const {
    if (y > background.getHeight() - camera.h) {
        return background.getHeight() - camera.h;
    } else if (y < 0) {
        return 0;
    } else {
        return y;
    }
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
    camera.x = checkBoundryX((background.getWidth() / 2) - camera.w / 2);
    camera.y = checkBoundryY((background.getHeight() / 2) - camera.h / 2); 
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
    background.render(0, 0, &camera);
}