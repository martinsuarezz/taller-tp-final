#include "Texture.h"
#include "Renderer.h"
#include <stdexcept>

Texture::Texture(Renderer& renderer): renderer(renderer){
	texture = NULL;
	originalWidth = 0;
	originalHeight = 0;
}

Texture::Texture(Texture&& other): renderer(other.renderer){
	this->texture = other.texture;
	this->width = other.width;
	this->height = other.height;
	this->originalWidth = other.originalWidth;
	this->originalHeight = other.originalHeight;
	other.texture = NULL;
}

Texture& Texture::operator=(Texture& other){
	this->texture = other.texture;
	this->width = other.width;
	this->height = other.height;
	this->originalWidth = other.originalWidth;
	this->originalHeight = other.originalHeight;
	return *this;
}

Texture::~Texture(){
	free();
}

bool Texture::loadFromFile(std::string path, bool transparecy, 
							SDL_Color transparencyColor){
	free();
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
		throw std::runtime_error(IMG_GetError());
	else{
		if (transparecy)
			SDL_SetColorKey(loadedSurface, SDL_TRUE, 
								SDL_MapRGB(loadedSurface->format,
								transparencyColor.r,
								transparencyColor.g,
								transparencyColor.b));

        newTexture = SDL_CreateTextureFromSurface(renderer.getSDLRenderer(),
													loadedSurface);
		if (newTexture == NULL)
			throw std::runtime_error(SDL_GetError());
		else {
			originalWidth = loadedSurface->w;
			width = originalWidth;
			originalHeight = loadedSurface->h;
			height = originalHeight;
		}

		SDL_FreeSurface(loadedSurface);
	}

	texture = newTexture;
	return texture != NULL;
}

bool Texture::loadFromRenderedText(std::string text, std::string fontName, 
									int fontSize, SDL_Color fontColor){
    free();
	
	std::string fontFullName = "fonts/" + fontName;
	TTF_Font* font = TTF_OpenFont(fontFullName.c_str(), fontSize);

	if (!font)
		throw std::runtime_error(TTF_GetError());
	
	SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), 
													fontColor);
	TTF_CloseFont(font);

	if (textSurface != NULL){
        texture = SDL_CreateTextureFromSurface(renderer.getSDLRenderer(),
												textSurface);
		if(texture == NULL)
			throw std::runtime_error(SDL_GetError());
		else {
			originalWidth = textSurface->w;
			width = originalWidth;
			originalHeight = textSurface->h;
			height = originalHeight;
		}

		SDL_FreeSurface(textSurface);
	}
	else
		throw std::runtime_error(TTF_GetError());

	return texture != NULL;
}

void Texture::free(){
	if (texture != NULL){
		SDL_DestroyTexture(texture);
		texture = NULL;
		originalWidth = 0;
		width = 0;
		originalHeight = 0;
		height = 0;
	}
}

void Texture::setColor(Uint8 red, Uint8 green, Uint8 blue){
	SDL_SetTextureColorMod(texture, red, green, blue);
}

void Texture::setBlendMode(SDL_BlendMode blending){
	SDL_SetTextureBlendMode(texture, blending);
}
		
void Texture::setAlpha(Uint8 alpha){
	SDL_SetTextureAlphaMod(texture, alpha);
}

void Texture::render(int x, int y, SDL_Rect* clip, double angle,
					SDL_Point* center, SDL_RendererFlip flip) const{
	SDL_Rect renderQuad = {x, y, width, height};

	if (clip != NULL){
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	
	SDL_RenderCopyEx(renderer.getSDLRenderer(), texture, clip, &renderQuad, 
					angle, center, flip);
}

void Texture::setWidth(int newWidth){
	width = newWidth;
}

void Texture::setHeight(int newHeight){
	height = newHeight;
}

void Texture::resetDimentions(){
	height = originalHeight;
	width = originalWidth;
}

int Texture::getWidth() const{
	return originalWidth;
}

int Texture::getHeight() const{
	return originalHeight;
}
