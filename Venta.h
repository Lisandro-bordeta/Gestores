#ifndef VENTA_H
#define VENTA_H

#include <string>
#include <vector>
#include "Carrito.h"

struct Venta{

    int id;
    std::string fecha;
    float total;

};

class HistorialVentas{

private:

    std::vector<Venta> ventas;

public:

    void registrarVenta(Carrito &carrito);
    void mostrarVentas();

};

#endif