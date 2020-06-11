#include "Texture.h"
#include "Window.h"
#include "Renderer.h"

int main(int argc, char* argv[]){

    TTF_Init();

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
	} else{
		//Set texture filtering to linear
		if(!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" )){
			printf( "Warning: Linear texture filtering not enabled!" );
		}
    }

    Window window("Ventana prueba", 600, 500);
    Renderer renderer = window.getRenderer();
    SDL_Delay(100);
    renderer.setDrawColor(255,255,255,255);
	renderer.clear();

    Texture people(renderer);
    Texture text(renderer);
    SDL_Color textColor = { 0, 0, 0 };

    people.loadFromFile("foo.png");
    text.loadFromRenderedText("RENDER ENGINE 3D XVIEW", textColor);
    people.render(150,50);
    people.render(180,50);
    people.render(125,50);
    text.render(10, 350);
    
    renderer.renderPresent();
    SDL_Delay(3000);
}
