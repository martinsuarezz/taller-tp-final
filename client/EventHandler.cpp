#include "EventHandler.h"
#include "Client.h"
#include "GraphicalInterface.h"
#include "IntentionsQueue.h"
#include "Intention/MoveIntention.h"
#include "Intention/QuitIntention.h"
#include "Intention/TimeoutIntention.h"
#include <iostream>

enum directions{UP, RIGHT, DOWN, LEFT};

EventHandler::EventHandler(Client& client, IntentionsQueue& intentions): client(client), intentions(intentions){}

int EventHandler::handleKeyDown(SDL_Event* event){
    if (event->key.repeat != 0)
        return 0;
    switch(event->key.keysym.sym){
        case SDLK_w:
            std::cout << "W down" << std::endl;
            intentions.push(new MoveIntention(UP));
            return 1;
        case SDLK_d:
            std::cout << "D down" << std::endl;
            intentions.push(new MoveIntention(RIGHT));
            return 1;
        case SDLK_s:
            std::cout << "S down" << std::endl;
            intentions.push(new MoveIntention(DOWN));
            return 1;
        case SDLK_a:
            std::cout << "A down" << std::endl;
            intentions.push(new MoveIntention(LEFT));
            return 1;
        case SDLK_m:
            std::cout << "Play up" << std::endl;
            client.stopPlaySong();
            return 1;
        case SDLK_PERIOD:
            std::cout << "Next up" << std::endl;
            client.nextSong();
            return 1;
        case SDLK_COMMA:
            std::cout << "Play up" << std::endl;
            client.previousSong();
            return 1;
        
        default:
            std::cout << event->key.keysym.sym << std::endl;
            return 0;
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
    switch(event->button.button){
        case SDL_BUTTON_LEFT:
            {
            std::cout << "Left mouse down" << std::endl;
            GraphicalInterface& gui = client.getGui();
            gui.handleLeftClick(event->button.x, event->button.y);
            try{
                int slot = gui.getInventorySlot(event->button.x, event->button.y);
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
            intentions.push(new QuitIntention());
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
    while (SDL_PollEvent(&event) && (counter < 20) && (counterTotal++ < maxTotalEvents)){
        counter += handleSingleEvent(&event);
    }
    intentions.push(new TimeoutIntention());
}