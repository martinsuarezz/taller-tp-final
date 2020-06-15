#include "Texture.h"
#include "Sound.h"
#include "Animation.h"

class AssetsLoader;

class PlayerGraphic{
    private:
        SDL_Rect rectangles[5];
        AssetsLoader& assets;
        Animation animation;
        int x;
        int y;

    public:
        PlayerGraphic(AssetsLoader& assets);
        void render(int frame);
        void moveRight();
        void idle();
};
