#ifndef REMOVE_ITEM_COMMAND_H
#define REMOVE_ITEM_COMMAND_H
#include "Command.h"

// Clase que modela el comando de que se quitó un ítem del inventario.

class RemoveItemCommand: public Command{
    private:
        int slot;

    public:
        // Recibe el slot del ítem a remover.
        RemoveItemCommand(int slot);

        // Le notifica al cliente que debe quitar el ítem del inventario.
        void execute(Client& client);

};

#endif
