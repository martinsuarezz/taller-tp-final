#ifndef REMOVE_MOB_COMMAND_H
#define REMOVE_MOB_COMMAND_H
#include "Command.h"

// Clase que modela que se removió una entidad del juego.

class RemoveMobCommand: public Command{
    private:
        int entityId;
        
    public:
        // Recibe la id de la entidad a remover.
        RemoveMobCommand(int entityId);

        // Notifica a la parte gráfica que debe remover la entidad
        // indicada.
        void execute(Client& client);

};

#endif
