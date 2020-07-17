#ifndef GOLD_CONTAINER_H
#define GOLD_CONTAINER_H

class MovableEntity;

class GoldContainer{
    private:
        int goldAmmount;
        int safeGold;
        MovableEntity& entity;
        int getMaxGold();
        void changeAmmount(int ammount);

    public:
        GoldContainer(MovableEntity& entity);
        void add(int ammount);
        void remove(int ammount);
        bool areAvailable(int ammount);
        void notifyDeath();


};

#endif
