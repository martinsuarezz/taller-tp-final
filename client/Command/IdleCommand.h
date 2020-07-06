#ifndef IDLE_COMMAND_H
#define IDLE_COMMAND_H
#include "Command.h"

// Clase que modela el comando Idle

class IdleCommand: public Command{
    private:
        int entityId;

    public:
        // Recibe la entidad correspondiente junto con las coordenadas
        // donde se debe ubicar.
        IdleCommand(int entityId, int x, int y);

        // Le notifica al cliente que la entidad indicada se encuentra idle.
        void execute(Client& client);

};

#endif
