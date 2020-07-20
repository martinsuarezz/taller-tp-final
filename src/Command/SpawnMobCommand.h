#ifndef SPAWN_MOB_COMMAND_H
#define SPAWN_MOB_COMMAND_H
#include "Command.h"

// Clase que modela un comando que se agregó un monstruo al juego.

class SpawnMobCommand: public Command{
    private:
        int entityId;
        int type;

    public:
        // Recibe el id del nuevo monstruo, su tipo y su ubicación.
        SpawnMobCommand(int entityId, int type, int x, int y);

        // Le notifica a la parte gráfica que debe agregar el monstruo
        // indicado.
        void execute(Client& client);

};

#endif
