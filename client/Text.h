#ifndef TEXT_H
#define TEXT_H
#include "Texture.h"
#include <SDL2/SDL.h>
#include <string>

class Renderer;

class Text{
    private:
        Texture texture;
        std::string fontName;
        int fontSize;
        SDL_Color fontColor;

    public:
        Text(Renderer& renderer, std::string text, std::string fontName,
            int fontSize = 24, SDL_Color fontColor = {0, 0, 0});
        
        void changeText(std::string newText);

        void render(int x, int y);
        Text(Text&&);


};

#endif
