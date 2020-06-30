#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H
#include <SDL2/SDL.h>

class Client;

class EventHandler{
    private:
        Client& client;
        int handleSingleEvent(SDL_Event* event);
        int handleKeyDown(SDL_Event* event);
        int handleKeyUp(SDL_Event* event);
        int handleMouseDown(SDL_Event* event);

    public:
        EventHandler(Client& client);
        void handle(int maxValidEvents, int maxTotalEvents);
        

};

#endif