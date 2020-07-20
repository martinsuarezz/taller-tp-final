#ifndef RANDOM_GENERATOR_H
#define RANDOM_GENERATOR_H

// Clase para obtener números aleatorios con distribución uniforme.
// Es un singleton.

class RandomGenerator{
    private:
        RandomGenerator();

    public:
        // Obtiene una referencia a la instancia del objeto.
        static RandomGenerator& getInstance();

        // Devuelve un número random en el rango [0, maxNumber)
        int getValue(int maxNumber) const;
        int operator()(int maxNumber) const;

        // Devuelve un número random en el rango [minNumber, maxNumber)
        int getValue(int minNumber, int maxNumber) const;
        int operator()(int minNumber, int maxNumber) const;

        // Prohibida la copia de la clase.
        RandomGenerator(RandomGenerator const&) = delete;
        void operator=(RandomGenerator const&)  = delete;

};

#endif
