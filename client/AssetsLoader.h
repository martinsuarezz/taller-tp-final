#ifndef _ASSETS_LOADER_H_
#define _ASSETS_LOADER_H_

#include <map>
#include <string>
#include "Sound.h"
#include "Texture.h"
#include "Renderer.h"

class AssetsLoader{
    private:
        std::map<std::string, Texture> textures;
        std::map<std::string, Sound> sounds;

    public:
        AssetsLoader(Renderer& renderer);
        Sound& getSound(const std::string& soundName);
        Texture& getTexture(const std::string& textureName);
};

#endif
