#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include <map>
#include <string>

// Clase para obtener valores de configuración del juego.
// Es un singleton.

class Configuration{
    private:
        std::map<std::string, int> map;
        Configuration();

    public:
        // Obtiene una referencia a la instancia del objeto
        // de configuración.
        static Configuration& getInstance();

        // Obtiene el valor de un parámetro de configuración.
        int getValue(std::string parameter) const;

        // Prohibida la copia de la clase.
        Configuration(Configuration const&) = delete;
        void operator=(Configuration const&)  = delete;

};

#endif
