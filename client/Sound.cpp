#include "Sound.h"
#include <stdexcept>

Sound::Sound(const std::string & path) {
    sound = Mix_LoadWAV(path.c_str());
    if (sound == NULL) {
        throw std::runtime_error("No se pudo cargar el sonido");
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
