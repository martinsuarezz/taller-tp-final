#include "Texture.h"
#include "Renderer.h"


Texture::Texture(Renderer& renderer): renderer(renderer){
	texture = NULL;
	width = 0;
	height = 0;
}

Texture::~Texture(){
	free();
}

bool Texture::loadFromFile(std::string path){
	free();
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(renderer.getSDLRenderer(), loadedSurface);
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			width = loadedSurface->w;
			height = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	//Return success
	texture = newTexture;
	return texture != NULL;
}

bool Texture::loadFromRenderedText( std::string textureText, SDL_Color textColor )
{
    TTF_Font* gFont = TTF_OpenFont( "Chantelli_Antiqua.ttf", 35 );
	//Get rid of preexisting texture
	free();
	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, textureText.c_str(), textColor );
    
	if(textSurface != NULL){
		//Create texture from surface pixels
        texture = SDL_CreateTextureFromSurface(renderer.getSDLRenderer(), textSurface);
		if(texture == NULL){
			printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			width = textSurface->w;
			height = textSurface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface( textSurface );
	}
	else
	{
		printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
	}

	
	//Return success
	return texture != NULL;
}

void Texture::free(){
	if (texture != NULL){
		SDL_DestroyTexture(texture);
		texture = NULL;
		width = 0;
		height = 0;
	}
}

void Texture::setColor(Uint8 red, Uint8 green, Uint8 blue){
	//Modulate texture rgb
	SDL_SetTextureColorMod(texture, red, green, blue);
}

void Texture::setBlendMode(SDL_BlendMode blending){
	//Set blending function
	SDL_SetTextureBlendMode(texture, blending);
}
		
void Texture::setAlpha(Uint8 alpha){
	//Modulate texture alpha
	SDL_SetTextureAlphaMod(texture, alpha);
}

void Texture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip){
	SDL_Rect renderQuad = { x, y, width, height };

	if( clip != NULL ){
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	SDL_RenderCopyEx(renderer.getSDLRenderer(), texture, clip, &renderQuad, angle, center, flip);
}

int Texture::getWidth(){
	return width;
}

int Texture::getHeight(){
	return height;
}
