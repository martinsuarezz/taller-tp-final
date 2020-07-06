#ifndef ITEM_H
#define ITEM_H
#include "Item.h"

class Texture;

class AssetsLoader;

// Clase que modela un item de la interfaz gráfica.

class Item{
    private:
        Texture& texture;
        int itemId;

    public:
        Item(int itemId, AssetsLoader& assets);

        // Renderiza el item en las coordenadas entregadas.
        void render(int x, int y);

        // Obtiene el id del ítem.
        int getItemId() const;
};

#endif
