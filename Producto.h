#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

class Producto{

private:

    int id;
    std::string nombre;
    std::string marca;
    std::string modelo;
    float precio;
    int stock;

public:

    Producto();
    Producto(int id,std::string nombre,std::string marca,std::string modelo,float precio,int stock);

    void mostrar();

    int getId();
    std::string getNombre();
    float getPrecio();
    int getStock();

    void reducirStock(int cantidad);
    void aumentarStock(int cantidad);

};

#endif