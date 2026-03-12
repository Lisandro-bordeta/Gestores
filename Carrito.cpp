#include <iostream>
#include "Carrito.h"

using namespace std;

void Carrito::agregarProducto(Producto* producto,int cantidad){

    if(producto==nullptr)
        return;

    if(cantidad>producto->getStock()){

        cout<<"Stock insuficiente\n";
        return;

    }

    ItemCarrito item;

    item.producto=producto;
    item.cantidad=cantidad;

    items.push_back(item);

    producto->reducirStock(cantidad);

}

void Carrito::mostrarCarrito(){

    for(auto &i:items){

        cout<<i.producto->getNombre()<<" x"<<i.cantidad<<endl;

    }

}

float Carrito::calcularTotal(){

    float total=0;

    for(auto &i:items){

        total+=i.producto->getPrecio()*i.cantidad;

    }

    return total;

}

void Carrito::limpiar(){

    items.clear();

}