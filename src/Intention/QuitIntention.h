#ifndef QUIT_INTENION_H
#define QUIT_INTENION_H
#include "Intention.h"

// Clase que modela la intención de cerrar la aplicación.

class QuitIntention: public Intention{
    private:
        
    public:
        QuitIntention();

        // Le notifica al juego que debe ser cerrado.
        void execute(Sender& game);
};

#endif
