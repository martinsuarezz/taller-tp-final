#include "AssetsLoader.h"
#include "Renderer.h"
#include "nlohmann/json.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using json = nlohmann::json;

void AssetsLoader::loadTextures(std::string file, Renderer& renderer){
    std::ifstream texturesConfig(file);
    json texturesJSON;
    texturesConfig >> texturesJSON;

    for (json::iterator it = texturesJSON.begin(); it != texturesJSON.end(); ++it) {
        Texture texture = Texture(renderer);
        std::string fileName = "images/" + std::string(it.value());
        std::string keyName(it.key());
        bool transparency = (keyName[0] != '$');
        texture.loadFromFile(fileName, transparency);
        textures.emplace(std::make_pair(keyName, std::move(texture)));
    }
}

void AssetsLoader::loadSounds(std::string file){
    std::ifstream soundsConfig(file);
    json soundsJSON;
    soundsConfig >> soundsJSON;

    for (json::iterator it = soundsJSON.begin(); it != soundsJSON.end(); ++it) {
        std::string fileName = "audio/" + std::string(it.value());
        Sound sound(fileName);
        std::string keyName(it.key());
        sounds.emplace(std::make_pair(keyName, std::move(sound)));
    }
}

void AssetsLoader::loadAnimationsSingle(std::vector<int>& dimensions, std::string& keyName){

}

void AssetsLoader::loadAnimationsMultiple(std::vector<int>& dimensions, std::string& keyName){
    std::vector<SDL_Rect> areas;
    int ammount = dimensions[0];
    int x = dimensions[1];
    int y = dimensions[2];
    int width = dimensions[3];
    int height = dimensions[4];
    for (int i = 0; i < ammount; i++){
        SDL_Rect area;
        area.x = x;
        area.y = y;
        area.w = width;
        area.h = height;
        x += width;
        areas.push_back(area);
    }
    animations.emplace(std::make_pair(keyName, std::move(areas)));
}

void AssetsLoader::loadAnimations(std::string file){
    std::ifstream animationsConfig(file);
    json animationsJSON;
    animationsConfig >> animationsJSON;

    for (json::iterator it = animationsJSON.begin(); it != animationsJSON.end(); ++it) {
        std::vector<int> dimensions = it.value();
        std::string keyName(it.key());
        if (dimensions[0] == 0)
            this->loadAnimationsSingle(dimensions, keyName);
        else
            this->loadAnimationsMultiple(dimensions, keyName);
    }
}

AssetsLoader::AssetsLoader(Renderer& renderer){
    this->loadTextures("images/roots.json", renderer);
    this->loadSounds("audio/roots.json");
    this->loadAnimations("animations/animation.json");
}

Texture& AssetsLoader::getTexture(const std::string& textureName){
    return textures.find(textureName)->second;
}

Sound& AssetsLoader::getSound(const std::string& soundName){
    return sounds.find(soundName)->second;
}

std::vector<SDL_Rect>& AssetsLoader::getAnimationFrames(const std::string& animationName){
    return animations.find(animationName)->second;
}