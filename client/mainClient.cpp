#include "Window.h"
#include "SDLHandler.h"
#include "Client.h"
#include <iostream>
#include <string>
#include "Configuration.h"
#include "ClassTypeSelector.h"

int main(int argc, char* argv[]){
    try{
        ClassTypeSelector(argc, argv);
        std::string race = argv[1];
        std::string type = argv[2];

        SDLHandler sdlH = SDLHandler(AUDIO | VIDEO | TIMER | EVENTS);

        Configuration& congif = Configuration::getInstance();
        
        sdlH.initializeMixer();
        sdlH.initializeImage();
        sdlH.initializeTTF();
        sdlH.setHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
        
        Window window("Argentum", congif.getValue("window_width"), congif.getValue("window_height"));

        Client client(window, race, type);

        client.run();
        return 0;
    }
    catch(...){
        return 1;
    }
    
}
