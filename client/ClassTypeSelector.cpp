#include "ClassTypeSelector.h"
#include <iostream>
#include <stdexcept>

ClassTypeSelector::ClassTypeSelector(int argc, char* argv[]){
    if (argc < 3){
        std::cerr << "Error: número de parámetros incorrectos" << std::endl;
        printHelp();
        throw std::runtime_error("");
    }
    std::string race(argv[1]);
    if (race != "human" && race != "elf" && race != "gnome" && race != "dwarf"){
        std::cerr << "Error: raza no reconocida" << std::endl;
        printHelp();
        throw std::runtime_error("");
    }
    std::string type(argv[2]);
    if (type != "mage" && type != "cleric" && type != "paladin" && type != "warrior"){
        std::cerr << "Error: raza no reconocida" << std::endl;
        printHelp();
        throw std::runtime_error("");
    }
}

void ClassTypeSelector::printHelp(){
    std::cout << "Corra el juego con ./argentum [raza] [clase]" << std::endl;
    std::cout << "Razas disponibles: human, elf, gnome, dwarf" << std::endl;
    std::cout << "Clases disponibles: mage, cleric, paladin, warrior" << std::endl;
}