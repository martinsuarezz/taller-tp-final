#ifndef TEXTURE_H
#define TEXTURE_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>

class Renderer;

// Clase que modela las texturas del juego.

class Texture{
	private:
		Renderer& renderer;
		SDL_Texture* texture;
		int originalWidth;
		int originalHeight;
		int width;
		int height;

		//Libera los recursos de la textura
		void free();

	public:
		Texture(Renderer& renderer);
		Texture(Texture&& other);
		~Texture();

		// Carga una imagen a la textura.
		bool loadFromFile(std::string path, 
							bool transparency = true,
							SDL_Color transparencyColor = {0,0,0});
		
		// Crea una imagen a partir del texto pasado por parámetro.
		bool loadFromRenderedText(std::string text, std::string fontName,
									int fontSize = 24, 
									SDL_Color fontColor = {0,0,0});

		// Modular el color de la textura.
		void setColor(Uint8 red, Uint8 green, Uint8 blue);

		// Establece el modo de blending.
		void setBlendMode(SDL_BlendMode blending);

		// Modifica la transparencia de la textura.
		void setAlpha(Uint8 alpha);
		
		// Renderiza la textura en las coordenadas dadas.
		void render(int x, int y, SDL_Rect* clip = NULL, 
					double angle = 0.0, SDL_Point* center = NULL, 
					SDL_RendererFlip flip = SDL_FLIP_NONE) const;

		// Cambia las dimensiones de la textura.
		void setWidth(int newWidth);
		void setHeight(int newHeight);

		// Reinicia las dimensiones de la textura a sus dimensiones
		// originales.
		void resetDimentions();

		Texture& operator=(Texture&);

		//Obtener dimensiones de la textura.
		int getWidth() const;
		int getHeight() const;
};

#endif
