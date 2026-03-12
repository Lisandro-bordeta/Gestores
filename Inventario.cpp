#include <iostream>
#include "Inventario.h"

using namespace std;

void Inventario::agregarProducto(){

    int id,stock;
    string nombre,marca,modelo;
    float precio;

    cout<<"ID: ";
    cin>>id;

    cout<<"Nombre: ";
    cin>>nombre;

    cout<<"Marca: ";
    cin>>marca;

    cout<<"Modelo: ";
    cin>>modelo;

    cout<<"Precio: ";
    cin>>precio;

    cout<<"Stock: ";
    cin>>stock;

    Producto p(id,nombre,marca,modelo,precio,stock);

    productos.push_back(p);

}

void Inventario::listarProductos(){

    for(auto &p:productos){
        p.mostrar();
    }

}

Producto* Inventario::buscarProducto(int id){

    for(auto &p:productos){

        if(p.getId()==id)
            return &p;

    }

    return nullptr;

}