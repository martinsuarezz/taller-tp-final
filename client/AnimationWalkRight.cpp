#include "AnimationWalkRight.h"
#define PLAYER_WALK_ANIMATION_FRAMES 5
#define PLAYER_WALK_RIGHT_ANIMATION_X 0
#define PLAYER_WALK_RIGHT_ANIMATION_Y 145
#define PLAYER_WALK_ANIMATION_WIDTH 25
#define PLAYER_WALK_ANIMATION_HEIGHT 45

AnimationWalkRight::AnimationWalkRight(Texture& texture, int xInitial, int yInitial, int xFinal, int yFinal): Animation(texture, xInitial, yInitial, xFinal, yFinal){
    for (int i = 0; i < PLAYER_WALK_ANIMATION_FRAMES; i++){
        SDL_Rect area;
        area.y = PLAYER_WALK_RIGHT_ANIMATION_Y;
        area.x = PLAYER_WALK_RIGHT_ANIMATION_X + i * PLAYER_WALK_ANIMATION_WIDTH;
        area.h = PLAYER_WALK_ANIMATION_HEIGHT;
        area.w = PLAYER_WALK_ANIMATION_WIDTH;
        areas.push_back(area);
    }
}