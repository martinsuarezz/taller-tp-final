#ifndef SHOP_DESCRIPTOR_H
#define SHOP_DESCRIPTOR_H

// Clase que contiene las descripciones de los items
// a vender por el comerciante.

class ShopDescriptor{
    private:

    public:
        ShopDescriptor();

        // Imprime la descripción de cierto item junto con
        // su precio y su índice de compra.
        void printItem(int index, int itemid, int itemPrice);


};

#endif
