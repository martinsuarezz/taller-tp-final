#include "Renderer.h"
#include "Window.h"
#include <string>
#include <stdexcept>

Renderer::Renderer(){
    renderer = NULL;
}

Renderer::~Renderer(){
    if (renderer)
        SDL_DestroyRenderer(renderer);
        
    renderer = NULL;
}

Renderer::Renderer(SDL_Window* window){
    renderer = SDL_CreateRenderer(window, -1, 
                    SDL_RENDERER_ACCELERATED);                

    if (renderer == NULL)
        throw std::runtime_error(SDL_GetError());
}

SDL_Renderer* Renderer::getSDLRenderer() const{
    return this->renderer;
}

void Renderer::renderPresent() const{
    SDL_RenderPresent(renderer);
}

void Renderer::clear() const{
    SDL_RenderClear(renderer);
}

void Renderer::setViewport(SDL_Rect* viewport){
    SDL_RenderSetViewport(renderer, viewport);
}

void Renderer::getViewport(SDL_Rect* rect){
    SDL_RenderGetViewport(renderer, rect);
}

void Renderer::resetViewport(){
    setViewport(NULL);
}

int Renderer::getHeight() const{
    SDL_Rect viewport;
    SDL_RenderGetViewport(renderer, &viewport);
    return viewport.h;
}

int Renderer::getWidth() const{
    SDL_Rect viewport;
    SDL_RenderGetViewport(renderer, &viewport);
    return viewport.w;
}

void Renderer::setDrawColor(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha){
    SDL_SetRenderDrawColor(renderer, red, green, blue, alpha);
}

Renderer::Renderer(Renderer&& other){
    this->renderer = other.renderer;
    other.renderer = NULL;
}

Renderer& Renderer::operator=(Renderer&& other){
    this->renderer = other.renderer;
    other.renderer = NULL;
    return *this;
}
