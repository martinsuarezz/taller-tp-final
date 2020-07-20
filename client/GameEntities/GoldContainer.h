#ifndef GOLD_CONTAINER_H
#define GOLD_CONTAINER_H

class MovableEntity;

// Contenedor de oro de una entidad.

class GoldContainer{
    private:
        int goldAmmount;
        int safeGold;
        MovableEntity& entity;
        int getMaxGold();
        void changeAmmount(int ammount);

    public:
        GoldContainer(MovableEntity& entity);

        // Agrega la cantidad de oro determinada
        // respetando el límite.
        void add(int ammount);

        // Remueve la cantidad de oro dada.
        void remove(int ammount);

        // Chequea si tiene disponible la cantidad
        // requerida de oro.
        bool areAvailable(int ammount);

        // Notifica que la entidad ha muerto, para
        // poder quitar la cantidad de oro correspondiente.
        void notifyDeath();

        // Setea la cantidad de oro seguro.
        void setSafeGold(int ammount);


};

#endif
