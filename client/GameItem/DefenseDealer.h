#ifndef DEFENSE_DEALER_H
#define DEFENSE_DEALER_H

// Clase que modela la parte de un item
// encargada de la defensa de daño.

class DefenseDealer{
    private:
        int minDefense;
        int maxDefense;

    public:
        DefenseDealer(int minDefense, int maxDefense);
        DefenseDealer(DefenseDealer&& other);

        // Obtiene la defensa del item.
        int getDefense();

};

#endif
