#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H
#include <SDL2/SDL.h>

class Client;

class IntentionsQueue;

// Clase que se encarga de manejar los eventos de entrada de SDL.

class EventHandler{
    private:
        Client& client;
        IntentionsQueue& intentions;
        bool storeIsOpen;
        int handleSingleEvent(SDL_Event* event);
        int handleKeyDown(SDL_Event* event);
        int handleKeyUp(SDL_Event* event);
        int handleMouseDown(SDL_Event* event);
        int handleRightMouseDown(SDL_Event* event);

    public:
        // Recibe una referencia a la cola de intenciones donde colocará
        // las intenciones de ejecución.
        EventHandler(Client& client, IntentionsQueue& intentions);

        // Recibe cuantos eventos máximos debe manejar.
        // maxValidEvents es el número máximo de eventos que sabe manejar.
        // maxTotalEventos es el número máximo de eventos totales 
        // a manejar e ignorar.
        void handle(int maxValidEvents, int maxTotalEvents);

        // Abre el negocio de compra de items y se prepara a recibir
        // eventos relacionados a presionar números en el teclado.
        void openStore();
};

#endif
