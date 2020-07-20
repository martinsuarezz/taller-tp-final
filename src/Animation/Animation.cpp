#include "Animation.h"
#include "../Texture.h"
#include "../Screen.h"
#include "../Configuration.h"
#include "../AssetsLoader.h"
#include <math.h>
#include <stdexcept>

Animation::Animation(Texture& texture, std::vector<SDL_Rect>& frames, 
                    int duration): texture(texture), frames(frames){
    ammountFrames = frames.size();
    frameDuration = duration / ammountFrames;
    elapsedMicroseconds = 0;
    currentFrame = 0;
    targetMicroseconds = frameDuration;
}

Animation::Animation(Animation&& other): texture(other.texture),
            frames(other.frames), ammountFrames(other.ammountFrames),
            frameDuration(other.frameDuration), 
            elapsedMicroseconds(other.elapsedMicroseconds),
            targetMicroseconds(other.targetMicroseconds),
            currentFrame(other.currentFrame){}

void Animation::render(int x, int y, int timeElapsed){
    if ((elapsedMicroseconds <= targetMicroseconds) && 
        ((elapsedMicroseconds += timeElapsed) >= targetMicroseconds)){
        currentFrame++;
        targetMicroseconds += frameDuration;
    }
    texture.render(x, y, &frames[currentFrame % ammountFrames]);
}


Animation::~Animation(){

}
