#ifndef SOUND_PLAYER_H
#define SOUND_PLAYER_H

class Sound;

class SoundPlayer{
    private:
        Sound& sound;
        int timeToPlay;
        int targetTime;
        int currentTime;

    public:
        SoundPlayer(Sound& sound, int timeToPlay);
        void update(int time);

};

#endif
