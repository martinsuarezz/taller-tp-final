#include "EventHandler.h"
#include "Client.h"
#include "GraphicalInterface.h"
#include <iostream>

EventHandler::EventHandler(Client& client): client(client){}

int EventHandler::handleKeyDown(SDL_Event* event){
    if (event->key.repeat != 0)
        return 0;
    switch(event->key.keysym.sym){
        case SDLK_w:
            std::cout << "W down" << std::endl;
            return 1;
        case SDLK_d:
            std::cout << "D down" << std::endl;
            return 1;
        case SDLK_s:
            std::cout << "S down" << std::endl;
            return 1;
        case SDLK_a:
            std::cout << "A down" << std::endl;
            return 1;
    }
    return 0;
}

int EventHandler::handleKeyUp(SDL_Event* event){
    switch(event->key.keysym.sym){
        case SDLK_w:
            std::cout << "W up" << std::endl;
            return 1;
        case SDLK_d:
            std::cout << "D up" << std::endl;
            return 1;
        case SDLK_s:
            std::cout << "S up" << std::endl;
            return 1;
        case SDLK_a:
            std::cout << "A up" << std::endl;
            return 1;
    }
    return 0;
}

int EventHandler::handleMouseDown(SDL_Event* event){
    //if (event->key.repeat != 0)
    //    return 0;
    switch(event->button.button){
        case SDL_BUTTON_LEFT:
            {
            std::cout << "Left mouse down" << std::endl;
            GraphicalInterface& gui = client.getGui();
            try{
                int slot = gui.getInventarySlot(event->button.x, event->button.y);
                std::cout << "Clicked slot: " << slot << std::endl;
                gui.selectSlot(slot); 
            }
            catch(...){
                gui.resetSelection();
            }
            std::cout << "(x,y)" << event->button.x << "," << event->button.y << std::endl;
            return 1;
            }

        case SDL_BUTTON_RIGHT:
            std::cout << "Right mouse down" << std::endl;
            return 1;
    }
    return 0;
}

int EventHandler::handleSingleEvent(SDL_Event* event){
    switch(event->type){
        case SDL_QUIT:
            std::cout << "Quit" << std::endl;
            client.stopExecution();
            return 1;
        case SDL_KEYDOWN:
            return handleKeyDown(event);
        case SDL_KEYUP:
            return handleKeyUp(event);
        case SDL_MOUSEBUTTONDOWN:
            return handleMouseDown(event);
    }
    return 0;
}

void EventHandler::handle(int maxEvents, int maxTotalEvents){
    SDL_Event event;
    int counter = 0;
    int counterTotal = 0;
    while (SDL_PollEvent(&event) && counter < 20 && counterTotal++ < maxTotalEvents){
        counter += handleSingleEvent(&event);
    }
}