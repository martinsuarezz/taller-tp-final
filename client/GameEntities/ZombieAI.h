#ifndef ZOMBIE_AI_H
#define ZOMBIE_AI_H

class Zombie;

class ZombieAI{
    private:
        Zombie& zombie;
        int x;
        int y;
        int visionRange;

    public:
        ZombieAI(Zombie& zombie, int visionRange);
        void notifyPlayerMovement(int xObj, int yObj);
        void update();

};

#endif
