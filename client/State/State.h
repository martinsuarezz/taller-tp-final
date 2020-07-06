#ifndef STATE_H
#define STATE_H

class MovableEntity;

// Clase que modela un estado en el que se puede encontrar
// una entidad dentro de la lógica del juego.

class State{
    protected:
        MovableEntity& entity;

    public:
        State(MovableEntity& entity);

        // Cualquier clase que herede de state debe implementar los
        // siguientes métodos.

        // Actualiza el estado según el tiempo indicado.
        virtual void update(int time) = 0;

        // Devuelve si el estado es válido.
        virtual bool isValid() = 0;

        // Activa el estado para que comience a ejecutarse.
        virtual void activate() = 0;

};

#endif
