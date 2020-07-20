#ifndef DAMAGE_DEALER_H
#define DAMAGE_DEALER_H

class DamageDealer{
    private:
        int minDamage;
        int maxDamage;
        int range;
        int duration;

    public:
        DamageDealer(int minDamage, int maxDamage, int range, int duration);
        DamageDealer(DamageDealer&& other);
        int getDamage();
        int getRange();
        int getDuration();

};

#endif
