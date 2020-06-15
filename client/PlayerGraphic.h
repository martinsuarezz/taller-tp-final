#include "Texture.h"
#include "Sound.h"
#include "Animation.h"


#define PLAYER_ANIMATION_WIDTH 25
#define PLAYER_ANIMATION_HEIGHT 45

#define PLAYER_WALK_ANIMATION_FRAMES 5
#define PLAYER_WALK_RIGHT_ANIMATION_X 0
#define PLAYER_WALK_RIGHT_ANIMATION_Y 145

#define PLAYER_IDLE_ANIMATION_FRAMES 1
#define PLAYER_IDLE_ANIMATION_X 0
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
        void moveRight(int distance);
        void idle();
};
