#include "Music.h"
#include <stdexcept>

Music::Music(const std::string & path) {
    music = Mix_LoadMUS(path.c_str());
    if (music == NULL) 
        throw std::runtime_error(Mix_GetError());
}

Music::~Music(){
    if (music)
        Mix_FreeMusic(music);
}

void Music::play(int times) {
    resume();
    if (Mix_PlayingMusic() == 0) {
        Mix_PlayMusic(music, times);
    }
}

void Music::pause() {
    if (Mix_PlayingMusic() == 1) {
        Mix_PauseMusic();
    }
}

void Music::resume() {
    if (isPaused())
        Mix_ResumeMusic();
}

bool Music::isPaused(){
    return Mix_PausedMusic() == 1;
}

void Music::halt() {
    if (Mix_PlayingMusic() == 1) {
        Mix_HaltMusic();
    }
}

Music::Music(Music&& other){
    this->music = other.music;
    other.music = NULL;
}
