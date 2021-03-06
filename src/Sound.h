#ifndef SOUND_H
#define SOUND_H

#include <SDL2/SDL_mixer.h>
#include <string>

// Clase que modela un sonido.

class Sound {
    private:
    Mix_Chunk * sound;

    public:
    //Initialize and loud sound.
    Sound(const std::string & path);

    // Constructor por movimiento.
    Sound(Sound&& other);

    //Deallocates memory.
    ~Sound();

    //Play sound n times on the selected channel.
    //Default channel is -1 = first free channel.
    void play(int times, int channel = -1);
};

#endif
