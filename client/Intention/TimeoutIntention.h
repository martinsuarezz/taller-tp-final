#ifndef TIMEOUT_INTENION_H
#define TIMEOUT_INTENION_H
#include "Intention.h"

// Clase que modela el paso del tiempo. De esta manera
// la lógica del juego funciona con el mismo reloj que la
// parte gráfica.

class TimeoutIntention: public Intention{
    private:
        
    public:
        TimeoutIntention();
        ~TimeoutIntention();

        // No realiza nada.
        void execute(Sender& game);
};

#endif
