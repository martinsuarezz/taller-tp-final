#include "Window.h"
#include "SDLHandler.h"
#include "Client.h"
#include <iostream>
#include "Configuration.h"
#include "Sound.h"

int main(int argc, char* argv[]){
    SDLHandler sdlH = SDLHandler(AUDIO | VIDEO | TIMER | EVENTS);

    Configuration& congif = Configuration::getInstance();
    
    sdlH.initializeMixer();
    sdlH.initializeImage();
    sdlH.initializeTTF();
    sdlH.setHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    
    Window window("Argentum", congif.getValue("window_width"), congif.getValue("window_height"));

    Client client(window);

    client.run();
    return 0;
}
