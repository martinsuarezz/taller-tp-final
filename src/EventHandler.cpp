#include "EventHandler.h"
#include "Client.h"
#include "Constants.h"
#include "GraphicalInterface.h"
#include "IntentionsQueue.h"
#include "Intention/MoveIntention.h"
#include "Intention/QuitIntention.h"
#include "Intention/TimeoutIntention.h"
#include "Intention/StopMoveIntention.h"
#include "Intention/MoveItemIntention.h"
#include "Intention/AttackIntention.h"
#include "Intention/PickUpIntention.h"
#include "Intention/InteractIntention.h"
#include "Intention/BuyItemIntention.h"
#include "Intention/TossIntention.h"

EventHandler::EventHandler(Client& client, IntentionsQueue& intentions): 
                    client(client), intentions(intentions), 
                    storeIsOpen(false){}

void EventHandler::openStore(){
    storeIsOpen = true;
}

int EventHandler::handleKeyDown(SDL_Event* event){
    if (event->key.repeat != 0)
        return 0;
    switch(event->key.keysym.sym){
        case SDLK_w:
            intentions.push(new MoveIntention(UP));
            storeIsOpen = false;
            return 1;
        case SDLK_d:
            intentions.push(new MoveIntention(RIGHT));
            storeIsOpen = false;
            return 1;
        case SDLK_s:
            intentions.push(new MoveIntention(DOWN));
            storeIsOpen = false;
            return 1;
        case SDLK_a:
            intentions.push(new MoveIntention(LEFT));
            storeIsOpen = false;
            return 1;
        case SDLK_h:
            intentions.push(new PickUpIntention());
            return 1;
        case SDLK_b:
            try{
                GraphicalInterface& gui = client.getGui();
                int slot = gui.getSelectedSlot();
                intentions.push(new TossIntention(slot));
                return 1;
            }
            catch(...) {}
        case SDLK_e:
            intentions.push(new InteractIntention());
            storeIsOpen = false;
            return 1;
        case SDLK_m:
            client.stopPlaySong();
            return 1;
        case SDLK_PERIOD:
            client.nextSong();
            return 1;
        case SDLK_COMMA:
            client.previousSong();
            return 1;
    }
    if (storeIsOpen && event->key.keysym.sym >= SDLK_1 && 
        event->key.keysym.sym <= SDLK_9){
        intentions.push(new BuyItemIntention(event->key.keysym.sym - SDLK_1));
    }
    return 0;
}

int EventHandler::handleKeyUp(SDL_Event* event){
    switch(event->key.keysym.sym){
        case SDLK_w:
            intentions.push(new StopMoveIntention());
            return 1;
        case SDLK_d:
            intentions.push(new StopMoveIntention());
            return 1;
        case SDLK_s:
            intentions.push(new StopMoveIntention());
            return 1;
        case SDLK_a:
            intentions.push(new StopMoveIntention());
            return 1;
    }
    return 0;
}

int EventHandler::handleRightMouseDown(SDL_Event* event){
    if (client.isClickOnMapScreen(event->button.x, event->button.y)){
        std::pair<int, int> coord = client.getMapCoordinates(event->button.x, 
                                                            event->button.y);
        intentions.push(new AttackIntention(coord.first, coord.second));
        return 1;
    }

    GraphicalInterface& gui = client.getGui();
    try{
        int newSlot = gui.getInventorySlot(event->button.x, event->button.y);
        int selectedSlot = gui.getSelectedSlot();
        intentions.push(new MoveItemIntention(selectedSlot, newSlot));
        gui.resetSelection();
    }
    catch(...){
        gui.resetSelection();
    }
    return 1;
}

int EventHandler::handleMouseDown(SDL_Event* event){
    switch(event->button.button){
        case SDL_BUTTON_LEFT:
            {
            GraphicalInterface& gui = client.getGui();
            try{
                int slot = gui.getInventorySlot(event->button.x, 
                                                event->button.y);
                gui.selectSlot(slot); 
            }
            catch(...){
                gui.resetSelection();
            }
            return 1;
            }
            break;

        case SDL_BUTTON_RIGHT:
            return handleRightMouseDown(event);
    }
    return 0;
}

int EventHandler::handleSingleEvent(SDL_Event* event){
    switch(event->type){
        case SDL_QUIT:
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
    while (SDL_PollEvent(&event) && (counter < 20) 
            && (counterTotal++ < maxTotalEvents)){
        counter += handleSingleEvent(&event);
    }
    intentions.push(new TimeoutIntention());
}
