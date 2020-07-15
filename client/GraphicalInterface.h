#ifndef GRAPHICAL_INTERFACE_H
#define GRAPHICAL_INTERFACE_H
#include <map>
#include "Item.h"
#include "Inventory.h"
#include "Texture.h"

class AssetsLoader;

class Text;

// Clase que modela la interfaz gráfica.

class GraphicalInterface{
    private:
        AssetsLoader& assets;
        Texture& gui;
        Text& health;
        Text& level;
        Text& experience;
        Text& mana;
        Inventory inventory;

    public:
        GraphicalInterface(AssetsLoader& assets);

        // Renderiza la interfaz gráfica.
        void render();

        // Agrega un ítem al inventario.
        void addItemInventory(int itemId, int position);

        // Remueve un ítem del inventario.
        void removeItemInventory(int position);

        // Mueve un ítem del inventario entre dos posiciones.
        void moveItemInventory(int from, int to);

        // Obtiene el slot del inventario correspondiente
        // a las coordenadas recibidas.
        int getInventorySlot(int x, int y) const;

        // Devuelve true si las coordenadas recibidas estan dentro
        // del slot del inventario indicado.
        bool slotIsInbound(int x, int y, int slot) const;

        // Selecciona el slot indicado del inventario.
        void selectSlot(int slot);

        // Reinicia la selección del slot del inventario.
        void resetSelection();

        // Devuelve el slot seleccionado.
        int getSelectedSlot() const;

        void updateHealth(int health);
        void updateLevel(int level);
        void updateExperience(int exp);
        void updateMana(int mana);

        ~GraphicalInterface();

};

#endif
