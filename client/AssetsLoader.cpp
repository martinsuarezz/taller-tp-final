#include "AssetsLoader.h"

AssetsLoader::AssetsLoader(Renderer& renderer){
    Texture texture0 = Texture(renderer);
    texture0.loadFromFile("Images/25.png");
    textures.emplace(std::make_pair<int, Texture>(0, std::move(texture0)));
    Sound sound0 = Sound("Audio/24.wav");
    sounds.emplace(std::make_pair<int, Sound>(0, std::move(sound0)));
}

Texture& AssetsLoader::getTexture(int textureId){
    return textures.find(textureId)->second;
}

Sound& AssetsLoader::getSound(int soundId){
    return sounds.find(soundId)->second;
}