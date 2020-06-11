#include "Texture.h"
#include "Window.h"
#include "Renderer.h"
#include "SDLHandler.h"

int main(int argc, char* argv[]){
    SDLHandler sdlH = SDLHandler(AUDIO | VIDEO | TIMER | EVENTS);
    sdlH.initializeMixer();
    sdlH.initializeImage();
    sdlH.initializeTTF();
    sdlH.setHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    
    Window window("Ventana prueba", 600, 600);
    Renderer& renderer = window.getRenderer();
    SDL_Delay(100);
    renderer.setDrawColor(255,255,255,255);
	renderer.clear();

    Texture people(renderer);
    Texture text(renderer);
    SDL_Color textColor = { 0, 0, 0 };

    people.loadFromFile("foo.png");
    text.loadFromRenderedText("RENDER ENGINE 3D XVIEW", "Chantelli_Antiqua.ttf", 25, textColor);
    people.render(150,50);
    people.render(180,50, NULL, 30);
    people.render(125,50, NULL, 123);
    text.render(10, 350);
    
    renderer.renderPresent();
    SDL_Delay(3000);
}
