#ifndef ATTACK_INTENION_H
#define ATTACK_INTENION_H
#include "Intention.h"

// Clase que modela intención de ataque.

class AttackIntention: public Intention{
    private:
        int x;
        int y;
        
    public:
        // Recibe las coordenadas del tile donde se planea atacar.
        AttackIntention(int x, int y);

        // Ejecuta la intención, indicandole al juego que el jugador
        // desea atacar a la posición indicada.
        void execute(Sender& game);
};

#endif
