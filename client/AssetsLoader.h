#ifndef _ASSETS_LOADER_H_
#define _ASSETS_LOADER_H_

#include <map>
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include "Sound.h"
#include "Texture.h"
#include "Renderer.h"
#include "Music.h"
#include "Text.h"

// Esta clase se encarga de cargar las texturas, sonidos
// y animaciones y devolver referencias a las mismas cuando
// sea necesario.

class AssetsLoader{
    private:
        std::map<std::string, Texture> textures;
        std::map<std::string, Sound> sounds;
        std::map<std::string, Text> texts;
        std::map<std::string, Music> songs;
        std::map<std::string, std::vector<SDL_Rect>> animations;

        // Métodos responsables de cargar los archivos leyendo
        // los correspondientes archivos json.
        void loadTextures(std::string file, Renderer& render);
        void loadTexts(Renderer& render);
        void loadSounds(std::string file);
        void loadSongs(std::string file);
        void loadAnimations(std::string file);
        void loadAnimationsSingle(std::vector<int>& dimensions, 
                                    std::string& keyName);
        void loadAnimationsMultiple(std::vector<int>& dimensions,
                                    std::string& keyName);

    public:
        AssetsLoader(Renderer& renderer);

        // Métodos para obtener referencias a los assets necesarios.
        Sound& getSound(const std::string& soundName);
        Texture& getTexture(const std::string& textureName);
        Texture& getBlank(const std::string& textureName);
        Text& getText(const std::string& textName);
        Music& getSong(const std::string& songName);
        std::vector<SDL_Rect>& getAnimationFrames(
                const std::string& animationName);
};

#endif
