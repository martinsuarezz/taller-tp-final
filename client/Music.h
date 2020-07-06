#ifndef MUSIC_H
#define MUSIC_H

#include <SDL2/SDL_mixer.h>
#include <string>

// Clase que modela una canción del juego.

class Music {
    private:
    Mix_Music* music;

    public:
    // Inicializa y carga la música.
    Music(const std::string& path);

    // Libera los recursos utilizados.
    ~Music();

    // Reproduce la canción x times.
    // Si recibe -1 reproduce la canción eternamente.
    void play(int times);
    
    // Pausa la música si se está reproduciendo.
    void pause();

    // Reproduce la música.
    void resume();

    // Detiene la música.
    void halt();

    // Devuelve si la música se está reproduciendo.
    bool isPaused();

    Music(Music&& other);
};

#endif
