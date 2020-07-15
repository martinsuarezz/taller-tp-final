#ifndef LEVEL_H
#define LEVEL_H

class MovableEntity;

class Level{
    private:
        int level;
        int experience;
        MovableEntity& entity;
        void changeExperience(int experience);
        void changeLevel(int level);
        int levelUpLimit();

    public:
        Level(MovableEntity& entity);
        int getLevel();
        void addExperience(int experience);

};

#endif
