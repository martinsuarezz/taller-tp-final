#include "Text.h"
#include "Texture.h"
#include "Renderer.h"
#include <SDL2/SDL.h>
#include <string>

Text::Text(Renderer& renderer, std::string text, std::string fontName,
                    int fontSize, SDL_Color fontColor): 
                    texture(std::move(Texture(renderer))), fontName(fontName){
    
    texture.loadFromRenderedText(text, fontName, fontSize, fontColor);
}

Text::Text(Text&& other): texture(std::move(other.texture)), fontName(other.fontName){

}

void Text::changeText(std::string newText){
    texture.loadFromRenderedText(newText, fontName);
}

void Text::render(int x, int y){
    texture.render(x, y);
}
