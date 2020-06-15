#include "Sound.h"
#include <stdexcept>

Sound::Sound(const std::string & path) {
    sound = Mix_LoadWAV(path.c_str());
    if (sound == NULL) {
        //Excepcion a cambiar en el futuro.
        throw std::invalid_argument(Mix_GetError());
    }
}

Sound::~Sound() {
    if (sound)
        Mix_FreeChunk(sound);
}

void Sound::play(int times, int channel) {
    Mix_PlayChannel(channel, sound, times);
}

Sound::Sound(Sound&& other){
    this->sound = other.sound;
    other.sound = NULL;
}
