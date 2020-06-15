#include "Texture.h"
#include "Sound.h"
#include "Animation.h"

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
