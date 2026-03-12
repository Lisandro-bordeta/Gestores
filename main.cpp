#include <iostream>
#include "Inventario.h"
#include "Carrito.h"
#include "Venta.h"

using namespace std;

int main(){

    Inventario inventario;
    Carrito carrito;
    HistorialVentas historial;

    int op;

    do{

        cout<<"\n1 Agregar producto\n";
        cout<<"2 Listar productos\n";
        cout<<"3 Agregar al carrito\n";
        cout<<"4 Ver carrito\n";
        cout<<"5 Registrar venta\n";
        cout<<"6 Historial ventas\n";
        cout<<"0 Salir\n";

        cin>>op;

        if(op==1){

            inventario.agregarProducto();

        }

        if(op==2){

            inventario.listarProductos();

        }

        if(op==3){

            int id,cantidad;

            cout<<"ID producto: ";
            cin>>id;

            cout<<"Cantidad: ";
            cin>>cantidad;

            Producto* p=inventario.buscarProducto(id);

            carrito.agregarProducto(p,cantidad);

        }

        if(op==4){

            carrito.mostrarCarrito();
            cout<<"Total: "<<carrito.calcularTotal()<<endl;

        }

        if(op==5){

            historial.registrarVenta(carrito);

        }

        if(op==6){

            historial.mostrarVentas();

        }

    }while(op!=0);

}