#ifndef PLAYER_MANA_COMMAND_H
#define PLAYER_MANA_COMMAND_H
#include "Command.h"

// Clase que modela el cambio de mana por
// parte del jugador.

class PlayerManaCommand: public Command{
    private:
        int mana;

    public:
        PlayerManaCommand(int mana);

        void execute(Client& client);

};

#endif
