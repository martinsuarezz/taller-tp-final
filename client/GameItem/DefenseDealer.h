#ifndef DEFENSE_DEALER_H
#define DEFENSE_DEALER_H

class DefenseDealer{
    private:
        int minDefense;
        int maxDefense;

    public:
        DefenseDealer(int minDefense, int maxDefense);
        DefenseDealer(DefenseDealer&& other);
        int getDefense();

};

#endif
