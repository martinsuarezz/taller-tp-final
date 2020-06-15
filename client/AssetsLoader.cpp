#include "AssetsLoader.h"

AssetsLoader::AssetsLoader(Renderer& renderer){
    Texture texture0 = Texture(renderer);
    texture0.loadFromFile("25.png");
    textures.emplace(std::make_pair<int, Texture>(0, std::move(texture0)));
}

Texture& AssetsLoader::getTexture(int textureId){
    return textures.find(textureId)->second;
}

Sound& AssetsLoader::getSound(int soundId){
    return sounds.find(soundId)->second;
}