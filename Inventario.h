#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <vector>
#include "Producto.h"

class Inventario{

private:

    std::vector<Producto> productos;

public:

    void agregarProducto();
    void listarProductos();
    Producto* buscarProducto(int id);

};

#endif