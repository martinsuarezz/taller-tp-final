#ifndef TEXTURE_H
#define TEXTURE_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>

class Renderer;

class Texture{
	private:
		Renderer& renderer;
		SDL_Texture* texture;

		//Image dimensions
		int width;
		int height;

	public:
		//Initializes variables
		Texture(Renderer& renderer);

		//Deallocates memory
		~Texture();

		// Carga una imagen a la textura
		bool loadFromFile( std::string path );
		
		// Crea una imagen a partir del texto pasado por parámetro.
		bool loadFromRenderedText(std::string text, std::string font, 
									int fontSize = 24, SDL_Color fontColor = {0,0,0});

		//Deallocates texture
		void free();

		// Modular el color de la textura
		void setColor(Uint8 red, Uint8 green, Uint8 blue);

		//Set blending
		void setBlendMode(SDL_BlendMode blending);

		// Modificar transparencia de la textura.
		void setAlpha( Uint8 alpha );
		
		// Renderiza la textura en las coordenadas dadas.
		void render(int x, int y, SDL_Rect* clip = NULL, 
					double angle = 0.0, SDL_Point* center = NULL, 
					SDL_RendererFlip flip = SDL_FLIP_NONE);

		//Obtener dimensiones de la textura.
		int getWidth();
		int getHeight();
};

#endif
