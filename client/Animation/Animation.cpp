#include "Animation.h"
#include "../Texture.h"
#include "../Screen.h"
#include "../Configuration.h"
#include "../AssetsLoader.h"
#include <math.h>
#include <iostream>
#include <stdexcept>

Animation::Animation(Texture& texture, std::vector<SDL_Rect>& frames, int duration): texture(texture), frames(frames), duration(duration){
    Configuration& config = Configuration::getInstance();
    ammountFrames = frames.size();
    targetMiliseconds = duration / ammountFrames;
    elapsedMiliseconds = 0;
    currentAnimation = 0;
    remainingFrames = (duration * config.getValue("fps")) / 1000;
}

void Animation::render(int x, int y){
    Configuration& config = Configuration::getInstance();
    int milisecondsPerFrame = 1000 / config.getValue("fps");
    if (elapsedMiliseconds <= targetMiliseconds && (elapsedMiliseconds += milisecondsPerFrame) >= targetMiliseconds){
        currentAnimation++;
        targetMiliseconds += duration / ammountFrames;
    }
    texture.render(x, y, &frames[currentAnimation % ammountFrames]);
    remainingFrames--;
}


Animation::~Animation(){

}