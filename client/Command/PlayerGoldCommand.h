#ifndef PLAYER_GOLD_COMMAND_H
#define PLAYER_GOLD_COMMAND_H
#include "Command.h"

// Clase que modela el cambio de oro por
// parte del jugador.

class PlayerGoldCommand: public Command{
    private:
        int gold;

    public:
        PlayerGoldCommand(int gold);

        void execute(Client& client);

};

#endif
