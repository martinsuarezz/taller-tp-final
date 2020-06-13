#include "Music.h"
#include <stdexcept>

Music::Music(const std::string & path) {
    music = Mix_LoadMUS(path.c_str());
    if (music == NULL) {
        //Excepcion a cambiar en el futuro.
        throw std::invalid_argument(Mix_GetError());
    }
}

Music::~Music() {
    Mix_FreeMusic(music);
}

void Music::play(int times) {
    if (Mix_PlayingMusic() == 0) {
        Mix_PlayMusic(music, times);
    }
}

void Music::pause() {
    if (Mix_PlayingMusic() == 1) {
        Mix_PlayingMusic();
    }
}

void Music::resume() {
    if (Mix_PausedMusic() == 1) {
        Mix_ResumeMusic();
    }
}

void Music::halt() {
    if (Mix_PlayingMusic() == 1) {
        Mix_HaltMusic();
    }
}
