#ifndef INTENTION_H
#define INTENTION_H

class Sender;

// Modela una intención de acción. El cliente la utiliza para
// notificarle a la lógica del juego que se intenta llevar a cabo
// una acción.

class Intention{
    protected:

    public:
        Intention();

        // Ejecuta la intención en la lógica del juego.
        virtual void execute(Sender& game) = 0;

};

#endif
