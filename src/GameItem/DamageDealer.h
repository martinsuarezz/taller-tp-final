#ifndef DAMAGE_DEALER_H
#define DAMAGE_DEALER_H

// Clase que modela la parte de un item
// encargada de realizar el daño.

class DamageDealer{
    private:
        int minDamage;
        int maxDamage;
        int range;
        int duration;

    public:
        DamageDealer(int minDamage, int maxDamage, int range, int duration);
        DamageDealer(DamageDealer&& other);

        // Obtiene los distintos atributos del item.
        int getDamage();
        int getRange();
        int getDuration();

};

#endif
