#ifndef HEALTH_H
#define HEALTH_H

class MovableEntity;

// Clase que modela la vida de la entidad.

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

        // Setea los atributos de la vida.
        void setMaxHealth(int maxHealth);
        void setHealthRegen(int healthRegen);

        // Notifica el paso del tiempo para regenerar la vida.
        void regenerate(int timeElapsed);

        // Agrega la vida determinada sin pasarse del límite.
        void addHealth(int health);

        // Quita vida.
        void dealDamage(int damage);

        // Obtiene los atributos.
        int getHealth();
        int getMaxHealth();

};

#endif
