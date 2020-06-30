#ifndef ENTITY_H
#define ENTITY_H

#include "Texture.h"
#include "Sound.h"
#include "WalkingAnimation.h"
#include "Action.h"
#include <memory>
#include <map>
#include <string>

class AssetsLoader;

class Screen;

class Entity{
    private:
        int x;
        int y;
        AssetsLoader& assets;
        Screen& screen;
        std::map<std::string, std::string> equiped;
        std::unique_ptr<Action> action;

    public:
        Entity(AssetsLoader& assets, Screen& screen, std::map<std::string, std::string> equiped, int x, int y);

        void update();
        int getX() const;
        int getY() const;
        int getRelativeX() const;
        int getRelativeY() const;
        void addX(int pixels);
        void addY(int pixels);
        void moveUp(int x, int y);
        void moveDown(int x, int y);
        void moveRight(int x, int y);
        void moveLeft(int x, int y);
        void idle(int x, int y);
        void meditate();
        void updateAction(Action* newAction);
        std::map<std::string, std::string>& getEquipedItems();
        bool isOnScreen() const;

        Entity(Entity&&);
};

#endif
