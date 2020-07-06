#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H
#include <string>
#include <vector>

class AssetsLoader;

// Clase que modela el reproductor de música.

class MusicPlayer{
    private:
        AssetsLoader& assets;
        std::vector<std::string> trackNames;
        int index;
        bool isStopped;
        void play();
        void stop();
        void resume();
        void pause();
        bool isPaused();
        bool isPlaying();

    public:
        MusicPlayer(AssetsLoader& assets);
        
        // Detiene o continúa la reproducción de música.
        void switchPlayStop();

        // Reproduce la próxima canción.
        void nextTrack();

        // Reproduce la canción anterior.
        void previousTrack();

        // Continua la reproducción de la lista. Si hay una canción
        // reproduciendose no hace nada, de otra manera continúa con
        // la próxima canción.
        void continuePlaying();
};

#endif
