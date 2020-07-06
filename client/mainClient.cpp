#include "Window.h"
#include "SDLHandler.h"
#include "Client.h"
#include <iostream>
#include "Configuration.h"

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

/*
int main(int argc, char* argv[]){
    SDLHandler sdlH = SDLHandler(AUDIO | VIDEO | TIMER | EVENTS);
    
    sdlH.initializeMixer();
    sdlH.initializeImage();
    sdlH.initializeTTF();
    sdlH.setHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    
    Window window("Ventana prueba", WINDOW_WIDTH, WINDOW_HEIGHT);
    Renderer& renderer = window.getRenderer();

    renderer.setDrawColor(200,255,255,255);
	renderer.clear();

    Texture text(renderer);
    text.loadFromRenderedText("Hola", "Fonts/Chantelli_Antiqua.ttf", 60);

    Texture dot(renderer);
    dot.loadFromFile("Images/dot.bmp", false, {0, 255, 255});
    Screen background("Images/bg.png", renderer, WINDOW_WIDTH, WINDOW_HEIGHT);
    background.moveToCenter();

    background.render();
    dot.render(50,50);
    text.render(50, 150);

    renderer.renderPresent();

    SDL_Delay(2000);

    //AssetsLoader assets(renderer);
    //PlayerGraphic player(assets);
    
    return 0;
}
*/