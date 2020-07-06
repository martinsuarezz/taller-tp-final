#ifndef WALKING_ACTION_H
#define WALKING_ACTION_H
#include <vector>
#include "../Animation/Animation.h"
#include "Action.h"
#include <map>

class Entity;

class AssetsLoader;

class WalkingAction: public Action{
    private:
        AssetsLoader& assets;
        std::string direction;
        int remainingFrames;

    public:
        WalkingAction(Entity& player, AssetsLoader& assets, std::string direction);

        // Notifica el paso del tiempo.
        void update();

        // Actualiza la Action de la entidad al movimiento en dicha dirección.
        // Si ya se está moviendo en esa dirección no hace nada.
        void walk(std::string direction);

        // Actualiza la Action de la entidad a idle.
        void idle();
};

#endif
