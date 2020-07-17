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

        // Calcula las distintas formulas de la lógica del juego.
        int getCriticalDamage(int damage) const;

        bool evadeAttack(int agility) const;

        int getTotalDefense(int armorDef, int helmetDef, int shieldDef) const;

        int getMaxHealth(std::string race, std::string type, int level) const;

        int getHealthRegen(std::string race) const;

        int getAttackExp(int damage, int defenderLevel, int attackerLeve) const;
        
        int getMaxMana(std::string race, std::string type, int level) const;

        int getManaRegen(std::string race) const;

        int getLevelUpExp(int level) const;

        int getWalkDuration(std::string race) const;

        int getRandomGold(int maxHealth) const;

        // Prohibida la copia de la clase.
        Configuration(Configuration const&) = delete;
        void operator=(Configuration const&)  = delete;

};

#endif
