#ifndef SPAWN_PLAYER_COMMAND_H
#define SPAWN_PLAYER_COMMAND_H
#include "Command.h"

// Clase que modela el comando de que se agregó un jugador al juego.

class SpawnPlayerCommand: public Command{
    private:
        int entityId;
        int type;

    public:
        // Recibe el id del nuevo jugador junto con sus coordenadas.
        SpawnPlayerCommand(int entityId, int x, int y);

        // Le notifica al cliente que debe agregar el jugador al juego.
        void execute(Client& client);

};

#endif
