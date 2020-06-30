#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H
#include <string>
#include <vector>

class AssetsLoader;

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
        
        void switchPlayStop();
        void nextTrack();
        void previousTrack();
        void continuePlaying();
};

#endif
