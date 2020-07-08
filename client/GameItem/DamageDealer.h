#ifndef DAMAGE_DEALER_H
#define DAMAGE_DEALER_H

class DamageDealer{
    private:
        int minDamage;
        int maxDamage;
        int range;

    public:
        DamageDealer(int minDamage, int maxDamage, int range);
        DamageDealer(DamageDealer&& other);
        int getDamage();
        int getRange();

};

#endif
