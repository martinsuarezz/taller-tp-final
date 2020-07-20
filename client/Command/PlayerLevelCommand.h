#ifndef PLAYER_LEVEL_COMMAND_H
#define PLAYER_LEVEL_COMMAND_H
#include "Command.h"

// Clase que modela el cambio de nivel por
// parte del jugador.

class PlayerLevelCommand: public Command{
    private:
        int level;

    public:
        PlayerLevelCommand(int level);

        void execute(Client& client);

};

#endif
