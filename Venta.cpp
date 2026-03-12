#include <iostream>
#include <ctime>
#include "Venta.h"

using namespace std;

string obtenerFecha(){

    time_t now=time(0);
    char* dt=ctime(&now);

    return string(dt);

}

void HistorialVentas::registrarVenta(Carrito &carrito){

    Venta v;

    v.id=ventas.size()+1;
    v.fecha=obtenerFecha();
    v.total=carrito.calcularTotal();

    ventas.push_back(v);

    carrito.limpiar();

    cout<<"Venta registrada\n";

}

void HistorialVentas::mostrarVentas(){

    for(auto &v:ventas){

        cout<<"\nVenta "<<v.id<<endl;
        cout<<"Fecha "<<v.fecha;
        cout<<"Total "<<v.total<<endl;

    }

}