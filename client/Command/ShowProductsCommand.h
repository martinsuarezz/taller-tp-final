#ifndef ATTACK_COMMAND_H
#define ATTACK_COMMAND_H
#include "Command.h"
#include <vector>

// Clase que modela que se accedió a un comerciante
// y se deben mostrar los productos que vende.

class ShowProductsCommand: public Command{
    private:
        std::vector<int> products;

    public:
        ShowProductsCommand(std::vector<int> products);

        void execute(Client& client);

};

#endif
