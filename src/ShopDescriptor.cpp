#include "ShopDescriptor.h"
#include "Constants.h"
#include <string>
#include <iostream>

ShopDescriptor::ShopDescriptor(){}

void ShopDescriptor::printItem(int index, int itemId, int price){
    std::string itemDescription = "";
    switch(itemId){
        case SWORD_ID:
            itemDescription = "Espada - Arma rápida de poco daño";
            break;
        case AXE_ID:
            itemDescription = "Hacha - Arma de daño medio";
            break;
        case HAMMER_ID:
            itemDescription = "Martillo - Arma lenta pero poderosa";
            break;
        case ICE_STAFF_ID:
            itemDescription = "Vara de fresno - Arma rápida a distancia de bajo costo de mana";
            break;
        case KNOT_STAFF_ID:
            itemDescription = "Báculo nudoso - Fuerte arma mágica a distancia";
            break;
        case ELFIC_FLUTE_ID:
            itemDescription = "Flauta élfica - Permite recuperar la vida";
            break;
        case CRIMP_STAFF_ID:
            itemDescription = "Báculo engarzado - Lanza un poderoso ataque mágico a distancia con alto costo de mana";
            break;
        case SIMPLE_BOW_ID:
            itemDescription = "Arco simple - Dispara flechas con bajo daño";
            break;
        case COMPOUND_BOW_ID:
            itemDescription = "Arco compuesto - Permite disparar flechas con un daño elevado";
            break;
        case LEATHER_ARMOR_ID:
            itemDescription = "Armadura de cuero - Protege una buena porción del daño recibido";
            break;
        case PLATE_ARMOR_ID:
            itemDescription = "Armadura de placas - Protege una gran cantidad del daño recibido";
            break;
        case BLUE_TUNIC_ID:
            itemDescription = "Túnica azul - Protege una buena porción del daño recibido";
            break;
        case HOOD_ID:
            itemDescription = "Capucha - Casco que protege una buena porción del daño recibido";
            break;
        case IRON_HELMET_ID:
            itemDescription = "Casco de hierro - Casco que protege una gran porción del daño recibido";
            break;
        case TURTLE_SHIELD_ID:
            itemDescription = "Escudo de tortuga - Escudo útil para defender contra ataques recibidos";
            break;
        case IRON_SHIELD_ID:
            itemDescription = "Escudo de hierro - Escudo que protege contra el daño recibido";
            break;
        case MAGIC_HAT_ID:
            itemDescription = "Sombrero mágico - Sombrergo que utiliza sus poderes mágicos para repeler daños recibidos";
            break;
    }
    std::cout << index << ". " <<itemDescription << " - $" << price << std::endl;
}