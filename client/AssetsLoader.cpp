#include "AssetsLoader.h"
#include "nlohmann/json.hpp"
#include <fstream>
#include <string>
#include <iostream>

using json = nlohmann::json;

AssetsLoader::AssetsLoader(Renderer& renderer){
    std::ifstream texturesConfig("Images/roots.json");
    json texturesJSON;
    texturesConfig >> texturesJSON;

    for (json::iterator it = texturesJSON.begin(); it != texturesJSON.end(); ++it) {
        Texture texture = Texture(renderer);
        std::string fileName = "Images/" + std::string(it.value());
        texture.loadFromFile(fileName);
        std::string keyName(it.key());
        textures.emplace(std::make_pair(keyName, std::move(texture)));
    }

    std::ifstream soundsConfig("Audio/roots.json");
    json soundsJSON;
    soundsConfig >> soundsJSON;

    for (json::iterator it = soundsJSON.begin(); it != soundsJSON.end(); ++it) {
        std::string fileName = "Audio/" + std::string(it.value());
        Sound sound(fileName);
        std::string keyName(it.key());
        sounds.emplace(std::make_pair(keyName, std::move(sound)));
    }
}

Texture& AssetsLoader::getTexture(const std::string& textureName){
    return textures.find(textureName)->second;
}

Sound& AssetsLoader::getSound(const std::string& soundName){
    return sounds.find(soundName)->second;
}