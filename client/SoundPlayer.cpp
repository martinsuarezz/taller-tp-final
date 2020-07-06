#include "SoundPlayer.h"
#include "Sound.h"

SoundPlayer::SoundPlayer(Sound& sound, int timeToPlay): sound(sound), timeToPlay(timeToPlay), targetTime(timeToPlay), currentTime(0){}

void SoundPlayer::update(int timeElapsed){
    if (currentTime <= targetTime && (currentTime += timeElapsed) >= targetTime){
        sound.play(1);
        targetTime += timeToPlay;
    }
        
}