#ifndef ATTACK_COMMAND_H
#define ATTACK_COMMAND_H
#include "Command.h"

// Clase que modela que se realizó un ataque.

class AttackCommand: public Command{
    private:
        int itemId;
        int duration;

    public:
        // Recibe el id del item con el que se atacó, las coordenadas
        // donde se atacó y la duración del ataque.
        AttackCommand(int itemId, int x, int y, int duration);

        void execute(Client& client);

};

#endif
