#ifndef _MUSIC_H_
#define _MUSIC_H_

#include <SDL2/SDL_mixer.h>
#include <string>

class Music {
    private:
    Mix_Music* music;

    public:
    //Initialize and load music.
    Music(const std::string& path);

    //Deallocates memory.
    ~Music();

    //Plays de music x times.
    //For infinite loop times = -1.
    void play(int times);
    
    //Pause the music if running.
    void pause();

    //Resume the music if paused.
    void resume();

    //Stop music.
    void halt();

    //
    bool isPaused();

    Music(Music&& other);
};

#endif
