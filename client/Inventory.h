#ifndef INVENTORY_H
#define INVENTORY_H
#include "Item.h"
#include <map>

class Sound;

class AssetsLoader;

// Clase que modela el inventario en la interfaz gráfica.

class Inventory{
    private:
        AssetsLoader& assets;
        std::map<int, Item> items;
        Sound& selectionSound;
        int slots;
        int selected;
        int getX(int slot) const;
        int getY(int slot) const;

    public:
        Inventory(AssetsLoader& assets);

        // Renderiza el inventario y sus items.
        void render();

        // Agrega un ítem en la posición indicada.
        void addItem(int itemId, int position);

        // Remueve el ítem de la posición indicada.
        void removeItem(int position);

        // Mueve un ítem entre dos posiciones.
        void moveItem(int from, int to);

        // Obtiene el slot del inventario que abarca las coordenadas
        // brindadas.
        int getSlot(int x, int y) const;

        // Devuelve si las coordenadas recibidas corresponden al slot indicado.
        bool slotIsInbound(int x, int y, int slot) const;

        // Selecciona el slot indicado para que la interfaz gráfica
        // así lo muestre.
        void selectSlot(int slot);

        // Devuelve el slot seleccionado.
        int getSelectedSlot() const;

        // Reinicia el slot seleccionado para que no haya ninguno.
        void resetSelection();
        ~Inventory();
};

#endif
