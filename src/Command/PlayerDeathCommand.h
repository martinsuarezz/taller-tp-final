#ifndef PLAYER_DEATH_COMMAND_H
#define PLAYER_DEATH_COMMAND_H
#include "Command.h"

// Clase que notifica que el jugador ha muerto.

class PlayerDeathCommand: public Command{
    private:
        int entityId;

    public:
        PlayerDeathCommand(int entityId);

        void execute(Client& client);

};

#endif
