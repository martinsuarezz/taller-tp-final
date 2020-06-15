#ifndef _ASSETS_LOADER_H_
#define _ASSETS_LOADER_H_

#include <map>
#include <string>
#include "Sound.h"
#include "Texture.h"
#include "Renderer.h"

class AssetsLoader{
    private:
        std::map<int, Texture> textures;
        std::map<int, Sound> sounds;

    public:
        AssetsLoader(Renderer& renderer);
        Sound& getSound(int soundId);
        Texture& getTexture(int textureId);
};

#endif
