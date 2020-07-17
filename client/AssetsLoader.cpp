#include "AssetsLoader.h"
#include "Renderer.h"
#include "Music.h"
#include "nlohmann/json.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using json = nlohmann::json;
#define FONT_SIZE 24

void AssetsLoader::loadTextures(std::string file, Renderer& renderer){
    std::ifstream texturesConfig(file);
    json texJSON;
    texturesConfig >> texJSON;

    for (json::iterator it = texJSON.begin(); it != texJSON.end(); ++it){
        Texture texture = Texture(renderer);
        std::string fileName = "images/" + std::string(it.value());
        std::string keyName(it.key());
        bool transparency = true;
        if (keyName[0] == '$'){
            transparency = false;
            keyName = keyName.substr(1);
        }
        texture.loadFromFile(fileName, transparency);
        textures.emplace(std::make_pair(keyName, std::move(texture)));
    }
}

void AssetsLoader::loadTexts(Renderer& renderer){
    Text health(renderer, "0", "diablo_h.ttf", FONT_SIZE, {237, 14, 14});
    texts.emplace("health", std::move(health));

    Text mana(renderer, "0", "diablo_h.ttf", FONT_SIZE, {173, 35, 232});
    texts.emplace("mana", std::move(mana));

    Text exp(renderer, "0", "diablo_h.ttf", FONT_SIZE, {122, 232, 32});
    texts.emplace("exp", std::move(exp));

    Text level(renderer, "1", "diablo_h.ttf", FONT_SIZE, {255, 232, 255});
    texts.emplace("level", std::move(level));

    Text gold(renderer, "0", "diablo_h.ttf", FONT_SIZE, {224, 235, 23});
    texts.emplace("gold", std::move(gold));
}

void AssetsLoader::loadSounds(std::string file){
    std::ifstream soundsConfig(file);
    json soundJSON;
    soundsConfig >> soundJSON;

    for (json::iterator it = soundJSON.begin(); it != soundJSON.end(); ++it){
        std::string fileName = "audio/" + std::string(it.value());
        Sound sound(fileName);
        std::string keyName(it.key());
        sounds.emplace(std::make_pair(keyName, std::move(sound)));
    }
}

void AssetsLoader::loadSongs(std::string file){
    std::ifstream musicConfig(file);
    json musicJSON;
    musicConfig >> musicJSON;

    for (json::iterator it = musicJSON.begin(); it != musicJSON.end(); ++it){
        std::string fileName = "music/" + std::string(it.value());
        Music song(fileName);
        std::string keyName(it.key());
        songs.emplace(std::make_pair(keyName, std::move(song)));
    }
}

void AssetsLoader::loadAnimationsSingle(std::vector<int>& dimensions,
                                        std::string& keyName){
    std::cout << "Warning: single animation not implemented!" << std::endl; 
}

void AssetsLoader::loadAnimationsMultiple(std::vector<int>& dimensions,
                                        std::string& keyName){
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
    json animJSON;
    animationsConfig >> animJSON;

    for (json::iterator it = animJSON.begin(); it != animJSON.end(); ++it){
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
    this->loadTexts(renderer);
    this->loadSounds("audio/roots.json");
    this->loadSongs("music/roots.json");
    this->loadAnimations("animations/animation.json");
}

Texture& AssetsLoader::getTexture(const std::string& textureName){
    return textures.at(textureName);
}

Text& AssetsLoader::getText(const std::string& textureName){
    return texts.at(textureName);
}

Sound& AssetsLoader::getSound(const std::string& soundName){
    return sounds.at(soundName);
}

Music& AssetsLoader::getSong(const std::string& songName){
    return songs.at(songName);
}

std::vector<SDL_Rect>& AssetsLoader::getAnimationFrames(
        const std::string& animationName){
    return animations.at(animationName);
}