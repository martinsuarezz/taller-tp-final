#ifndef IDLE_ACTION_H
#define IDLE_ACTION_H
#include <vector>
#include <map>
#include <string>
#include "../Animation/Animation.h"
#include "Action.h"

class Entity;

class AssetsLoader;

class IdleAction: public Action{
    private:
        AssetsLoader& assets;

    public:
        IdleAction(Entity& player, AssetsLoader& assets);

        // Notifica el paso del tiempo.
        void update(int timeElpased);

        // Cambia la Action de la entidad a WalkingAction en la dirección
        // indicada.
        void walk(std::string direction);

        // No hace nada.
        void idle();
};

#endif
