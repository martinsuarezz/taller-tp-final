#ifndef REMOVE_ITEM_MAP_COMMAND_H
#define REMOVE_ITEM_MAP_COMMAND_H
#include "Command.h"

// Clase que modela que se quitó un item del mapa.

class RemoveItemMapCommand: public Command{
    private:

    public:
        RemoveItemMapCommand(int x, int y);

        void execute(Client& client);

};

#endif
