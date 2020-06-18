#ifndef _PLAYER_GRAPHIC_H_
#define _PLAYER_GRAPHIC_H_

#include "Texture.h"
#include "Sound.h"
#include "WalkingAnimation.h"
#include <memory>

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

class Screen;

class PlayerGraphic{
    private:
        AssetsLoader& assets;
        //Animation animation;
        std::unique_ptr<Animation> animation;
        int x;
        int y;

    public:
        PlayerGraphic(AssetsLoader& assets, int x, int y);

        void render(Screen& background);
        int getX();
        int getY();
        void addX(int pixels);
        void addY(int pixels);
        void moveUp(int distance);
        void moveDown(int distance);
        void moveRight(int distance);
        void moveLeft(int distance);
        void idle();
        void updateAnimation(Animation* newAnimation);

        Sound& getSound();
        Texture& getBodyAsset();
};

#endif
