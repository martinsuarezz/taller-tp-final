#ifndef PLAYER_REVIVE_COMMAND_H
#define PLAYER_REVIVE_COMMAND_H
#include "Command.h"

// Clase que modela que el jugador fue revivido.

class PlayerReviveCommand: public Command{
    private:
        int entityId;

    public:
        PlayerReviveCommand(int entityId);

        void execute(Client& client);

};

#endif
