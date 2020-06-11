#include "SDLHandler.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <cstdarg>
#include <stdexcept>
#include <iostream>

SDLHandler::SDLHandler(Uint32 flags): mixerWasInitialized(false){
    SDL_Init(flags);
}

SDLHandler::~SDLHandler(){
    if (mixerWasInitialized)
        Mix_CloseAudio();
    if (IMG_Init(0))
        IMG_Quit();
    if (TTF_WasInit())
        TTF_Quit();
    SDL_Quit();
}

void SDLHandler::initializeImage(){
    if (!IMG_Init(0)){
        if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG |IMG_INIT_TIF) == 0)
            throw std::runtime_error(IMG_GetError());
    }
}

void SDLHandler::initializeTTF(){
    if (!TTF_WasInit()){
        if (TTF_Init() == -1)
            throw std::runtime_error(TTF_GetError());
    }
}

void SDLHandler::initializeMixer(int frequency, int channels, 
                                    Uint16 format, int chunksize){
    if (mixerWasInitialized)
        return;
    if (Mix_OpenAudio(frequency, format, channels, chunksize) == -1)
        throw std::runtime_error(Mix_GetError());
    mixerWasInitialized = true;
}

void SDLHandler::setHint(const char* name, const char* value){
    if (!SDL_SetHint(name, value))
		std::cout << "Warning: " << name << "not enabled!" << std::endl;
}