#include "AnimationIdle.h"
#define PLAYER_IDLE_ANIMATION_FRAMES 1
#define PLAYER_IDLE_ANIMATION_X 0
#define PLAYER_IDLE_ANIMATION_Y 10
#define PLAYER_IDLE_ANIMATION_WIDTH 25
#define PLAYER_IDLE_ANIMATION_HEIGHT 45

AnimationIdle::AnimationIdle(Texture& texture): Animation(texture){
    for (int i = 0; i < PLAYER_IDLE_ANIMATION_FRAMES; i++){
        SDL_Rect area;
        area.y = PLAYER_IDLE_ANIMATION_Y;
        area.x = PLAYER_IDLE_ANIMATION_X + i * PLAYER_IDLE_ANIMATION_WIDTH;
        area.h = PLAYER_IDLE_ANIMATION_HEIGHT;
        area.w = PLAYER_IDLE_ANIMATION_WIDTH;
        areas.push_back(area);
    }
}