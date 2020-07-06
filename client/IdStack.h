#ifndef ID_STACK_H
#define ID_STACK_H
#include <stack>

// Clase que modela una cola de IDs para las entidades
// que así lo requieran. Nunca se agotan sus elementos.

class IdStack{
    private:
        std::stack<int> stack;

    public:
        IdStack();

        // Devuelve la menor ID disponible.
        int pop();

        // Agrega una id que no se utiliza más.
        void push(int id);

};

#endif
