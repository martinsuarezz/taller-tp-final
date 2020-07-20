#ifndef PLAYER_EXP_COMMAND_H
#define PLAYER_EXP_COMMAND_H
#include "Command.h"

// Clase que modela el cambio de experiencia por
// parte del jugador.

class PlayerExpCommand: public Command{
    private:
        int experience;

    public:
        PlayerExpCommand(int experience);

        void execute(Client& client);

};

#endif
