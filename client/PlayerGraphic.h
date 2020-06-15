#ifndef _PLAYER_GRAPHIC_H_
#define _PLAYER_GRAPHIC_H_

#include "Texture.h"
#include "Sound.h"
#include "Animation.h"

#define PLAYER_ANIMATION_WIDTH 25
#define PLAYER_ANIMATION_HEIGHT 45
#define PLAYER_ANIMATION_X 0

#define PLAYER_WALK_Y_ANIMATION_FRAMES 6
#define PLAYER_WALK_Y_UP_ANIMATION_Y 55
#define PLAYER_WALK_Y_DOWN_ANIMATION_Y 10

#define PLAYER_WALK_X_ANIMATION_FRAMES 5
#define PLAYER_WALK_RIGHT_ANIMATION_Y 145
#define PLAYER_WALK_LEFT_ANIMATION_Y 100


#define PLAYER_IDLE_ANIMATION_FRAMES 1
#define PLAYER_IDLE_ANIMATION_Y 10


class AssetsLoader;

class PlayerGraphic{
    private:
        AssetsLoader& assets;
        Animation animation;
        int x;
        int y;

    public:
        PlayerGraphic(AssetsLoader& assets);
        void render(int frame);

        void moveUp(int distance);
        void moveDown(int distance);
        void moveRight(int distance);
        void moveLeft(int distance);
        void idle();
};

#endif
