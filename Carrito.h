#ifndef CARRITO_H
#define CARRITO_H

#include <vector>
#include "Producto.h"

struct ItemCarrito{

    Producto* producto;
    int cantidad;

};

class Carrito{

private:

    std::vector<ItemCarrito> items;

public:

    void agregarProducto(Producto* producto,int cantidad);
    void mostrarCarrito();
    float calcularTotal();
    void limpiar();

};

#endif