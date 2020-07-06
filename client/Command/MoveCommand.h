#ifndef MOVE_COMMAND_H
#define MOVE_COMMAND_H
#include "Command.h"

// Clase que modela el comando de movimiento.

class MoveCommand: public Command{
    private:
        int entityId;
        int direction;

    public:
        // Recibe la entidad correspondiente junto con las coordenadas
        // donde se debe ubicar y la dirección de movimiento.
        MoveCommand(int entityId, int direction, int x, int y);

        // Le notifica al cliente que la entidad indicada se 
        // encuentra moviéndose.
        void execute(Client& client);

};

#endif
