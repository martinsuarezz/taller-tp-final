#ifndef PLAYER_GRAPHIC_H
#define PLAYER_GRAPHIC_H

#include "Texture.h"
#include "Sound.h"
#include "WalkingAnimation.h"
#include "Action.h"
#include <memory>

class AssetsLoader;

class Screen;

class PlayerGraphic{
    private:
        int x;
        int y;
        AssetsLoader& assets;
        Screen& screen;
        std::unique_ptr<Action> action;

    public:
        PlayerGraphic(AssetsLoader& assets, Screen& screen, int x, int y);

        void render();
        int getX() const;
        int getY() const;
        int getRelativeX() const;
        int getRelativeY() const;
        void addX(int pixels);
        void addY(int pixels);
        void moveUp(int distance);
        void moveDown(int distance);
        void moveRight(int distance);
        void moveLeft(int distance);
        void updateAction(Action* newAction);

        Sound& getSound();
        Texture& getBodyAsset();
};

#endif
