#ifndef LEVEL_H
#define LEVEL_H

class MovableEntity;

// Clase que modela el nivel de la unidad.

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

        // Obtiene el nivel actual.
        int getLevel();

        // Agrega experiencia.
        void addExperience(int experience);

};

#endif
