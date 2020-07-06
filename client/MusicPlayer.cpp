#include "MusicPlayer.h"
#include "nlohmann/json.hpp"
#include "AssetsLoader.h"
#include "Music.h"
#include <SDL2/SDL_mixer.h>
#include <fstream>
#include <string>

using json = nlohmann::json;

MusicPlayer::MusicPlayer(AssetsLoader& assets): assets(assets), index(0),
                                                isStopped(false){
    std::string tracksFile = "music/playableTracks.json";
    std::ifstream tracksConfig(tracksFile);
    json tracksJSON;
    tracksConfig >> tracksJSON;

    std::vector<std::string> tracksNew = tracksJSON["tracks"];
    trackNames.swap(tracksNew);
}

void MusicPlayer::play(){
    Music& track = assets.getSong(trackNames[index]);
    isStopped = false;
    track.play(1);
}

void MusicPlayer::resume(){
    Music& track = assets.getSong(trackNames[index]);
    isStopped = false;
    track.resume();
}

void MusicPlayer::stop(){
    Music& track = assets.getSong(trackNames[index]);
    isStopped = true;
    track.halt();
}

void MusicPlayer::pause(){
    Music& track = assets.getSong(trackNames[index]);
    isStopped = true;
    track.pause();
}

void MusicPlayer::switchPlayStop(){
    if (isPaused())
        resume();
    else if (isPlaying())
        pause();
    else
        play();
}

void MusicPlayer::nextTrack(){
    if (isPlaying())
        stop();
    index++;
    if (index >= (int) trackNames.size())
        index = 0;
    play();
}

void MusicPlayer::previousTrack(){
    if (isPlaying())
        stop();
    index--;
    if (index < 0)
        index = (int) trackNames.size() - 1;
    play();
}

bool MusicPlayer::isPlaying(){
    return Mix_PlayingMusic() == 1;
}

bool MusicPlayer::isPaused(){
    return Mix_PausedMusic() == 1;
}

void MusicPlayer::continuePlaying(){
    if (isPlaying() || isStopped)
        return;
    nextTrack();
}
