#ifndef MANA_H
#define MANA_H

class MovableEntity;

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
        void setMaxMana(int maxHealth);
        void setManaRegen(int healthRegen);
        void regenerate(int timeElapsed);
        void addMana(int health);
        void removeMana(int removed);
        int getMana();

};

#endif
