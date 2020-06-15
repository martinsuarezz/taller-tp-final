#include "Texture.h"
#include "Sound.h"
#include "Animation.h"

class AssetsLoader;

class Screen;

class PlayerGraphic{
    private:
        AssetsLoader& assets;
        Animation animation;
        int x;
        int y;

    public:
        PlayerGraphic(AssetsLoader& assets);
        void render(int frame, Screen& background);
        int getX();
        int getY();
        void moveRight(int distance);
        void idle();
};
