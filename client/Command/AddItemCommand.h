#ifndef ADD_ITEM_COMMAND_H
#define ADD_ITEM_COMMAND_H
#include "Command.h"

// Clase que modela el comando de que se agregó un item al inventario
// del jugador.

class AddItemCommand: public Command{
    private:
        int itemId;
        int slot;

    public:
        // Recibe el id y slot del nuevo item en el inventario.
        AddItemCommand(int itemId, int slot);

        // Le notifica al cliente que debe agregar el item al inventario.
        void execute(Client& client);

};

#endif
