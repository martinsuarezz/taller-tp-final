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

class AssetsLoader{
    private:
        std::map<std::string, Texture> textures;
        std::map<std::string, Sound> sounds;
        std::map<std::string, Music> songs;
        std::map<std::string, std::vector<SDL_Rect>> animations;
        void loadTextures(std::string file, Renderer& render);
        void loadSounds(std::string file);
        void loadSongs(std::string file);
        void loadAnimations(std::string file);
        void loadAnimationsSingle(std::vector<int>& dimensions, std::string& keyName);
        void loadAnimationsMultiple(std::vector<int>& dimensions, std::string& keyName);

    public:
        AssetsLoader(Renderer& renderer);
        Sound& getSound(const std::string& soundName);
        Texture& getTexture(const std::string& textureName);
        Music& getSong(const std::string& songName);
        std::vector<SDL_Rect>& getAnimationFrames(const std::string& animationName);
};

#endif
