#ifndef SOUND_PLAYER_H
#define SOUND_PLAYER_H

class Sound;

// Clase que contiene un sonido y lo reproduce
// cada cierta cantidad de tiempo

class SoundPlayer{
    private:
        Sound& sound;
        int timeToPlay;
        int targetTime;
        int currentTime;

    public:
        // Se le pasa el sonido a reproducir. Lo reproduce en
        // múltiplos de timeToPlay.
        SoundPlayer(Sound& sound, int timeToPlay);

        // Avisa la actualizacion del tiempo.
        void update(int time);

};

#endif
