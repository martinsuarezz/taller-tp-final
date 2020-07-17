#ifndef HEALTH_H
#define HEALTH_H

class MovableEntity;

class Health{
    private:
        int damage;
        int maxHealth;
        int regenRate;
        int timeElapsed;
        MovableEntity& entity;
        void changeHealth(int value);

    public:
        Health(MovableEntity& entity);
        void setMaxHealth(int maxHealth);
        void setHealthRegen(int healthRegen);
        void regenerate(int timeElapsed);
        void addHealth(int health);
        void dealDamage(int damage);
        int getHealth();
        int getMaxHealth();

};

#endif
