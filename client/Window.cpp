#include "Window.h"
#include <string>
#include <stdexcept>

Window::Window(std::string name, int width, int height, 
                int x, int y, Uint32 flags){
    
    SDL_Window* newWindow = SDL_CreateWindow(name.c_str(), x, y, 
                                            width, height, flags);

    if (newWindow == NULL)
        throw std::runtime_error("Error creating display window");

    renderer = Renderer(newWindow);
    window = newWindow;
    this->height = height;
    this->width = width;
}

Renderer Window::getRenderer(){
    return renderer;
}

SDL_Window* Window::getSDLWindow() const{
    return window;
}
