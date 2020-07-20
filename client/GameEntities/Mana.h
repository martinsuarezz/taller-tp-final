#ifndef MANA_H
#define MANA_H

class MovableEntity;

// Clase que modela la mana de una entidad.

class Mana{
    private:
        int depleted;
        int maxMana;
        int regenRate;
        int timeElapsed;
        MovableEntity& entity;
        void changeMana(int value);

    public:
        Mana(MovableEntity& entity);

        // Setea los atributos.
        void setMaxMana(int maxHealth);
        void setManaRegen(int healthRegen);

        // Regenera la mana recibiendo la cantidad de tiempo
        // que pasó.
        void regenerate(int timeElapsed);

        // Agrega mana sin superar el límite.
        void addMana(int health);

        // Quita mana.
        void removeMana(int removed);

        // Obtiene la mana actual.
        int getMana();

};

#endif
