#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;


struct Producto{
    int id;
    string codigo;
    string nombre;
    string marca;
    string modelo;
    float precioCompra;
    float precioVenta;
    string foto;
    int stock;
};

vector<Producto> productos;

int generarID(){

    int maxID = 0;

    for(auto &p : productos){
        if(p.id > maxID){
            maxID = p.id;
        }
    }

    return maxID + 1;
}


struct ItemCarrito{
    Producto producto;
    int cantidad;
};

vector<ItemCarrito> carrito;

void guardarProductos(){
    ofstream file("productos.txt");

    for(auto &p : productos){
        file<<p.id<<"|"<<p.codigo<<"|"<<p.nombre<<"|"<<p.marca<<"|"<<p.modelo<<"|"
            <<p.precioCompra<<"|"<<p.precioVenta<<"|"<<p.foto<<"|"<<p.stock<<endl;
    }

    file.close();
}

void cargarProductos(){
    ifstream file("productos.txt");

    if(!file.is_open()) return;

    Producto p;
    string linea;

    while(getline(file,linea)){
        string datos[9];
        int i=0;

        string temp="";
        for(char c:linea){
            if(c=='|'){
                datos[i++]=temp;
                temp="";
            }else{
                temp+=c;
            }
        }
        datos[i]=temp;

        p.id=stoi(datos[0]);
        p.codigo=datos[1];
        p.nombre=datos[2];
        p.marca=datos[3];
        p.modelo=datos[4];
        p.precioCompra=stof(datos[5]);
        p.precioVenta=stof(datos[6]);
        p.foto=datos[7];
        p.stock=stoi(datos[8]);

        productos.push_back(p);
    }

    file.close();
}

void agregarProducto(){

    Producto p;

    p.id = generarID();

    cout<<"Codigo barras: ";
    cin>>p.codigo;

    cout<<"Producto: ";
    cin>>p.nombre;

    cout<<"Marca: ";
    cin>>p.marca;

    cout<<"Modelo: ";
    cin>>p.modelo;

    cout<<"Precio compra: ";
    cin>>p.precioCompra;

    cout<<"Precio venta: ";
    cin>>p.precioVenta;

    cout<<"Foto (ruta): ";
    cin>>p.foto;

    cout<<"Stock: ";
    cin>>p.stock;

    productos.push_back(p);

    guardarProductos();

    cout<<"Producto agregado con ID: "<<p.id<<endl;
}

void listarProductos(){
    for(auto &p : productos){

        cout<<"\n------------------\n";
        cout<<"ID: "<<p.id<<endl;
        cout<<"Codigo: "<<p.codigo<<endl;
        cout<<"Producto: "<<p.nombre<<endl;
        cout<<"Marca: "<<p.marca<<endl;
        cout<<"Modelo: "<<p.modelo<<endl;
        cout<<"Precio compra: "<<p.precioCompra<<endl;
        cout<<"Precio venta: "<<p.precioVenta<<endl;
        cout<<"Stock: "<<p.stock<<endl;
    }
}

void buscarProducto(){
    string texto;

    cout<<"Buscar: ";
    cin>>texto;

    for(auto &p : productos){

        if(p.nombre==texto || p.marca==texto || p.modelo==texto){

            cout<<"\nID: "<<p.id<<endl;
            cout<<"Producto: "<<p.nombre<<endl;
            cout<<"Marca: "<<p.marca<<endl;
            cout<<"Modelo: "<<p.modelo<<endl;
            cout<<"Precio: "<<p.precioVenta<<endl;
            cout<<"Stock: "<<p.stock<<endl;
        }
    }
}

void buscarCodigo(){
    string codigo;

    cout<<"Codigo barras: ";
    cin>>codigo;

    for(auto &p : productos){
        if(p.codigo==codigo){

            cout<<"\nProducto encontrado\n";
            cout<<p.nombre<<" "<<p.marca<<" "<<p.modelo<<endl;
            cout<<"Precio: "<<p.precioVenta<<endl;
            cout<<"Stock: "<<p.stock<<endl;
        }
    }
}

void editarProducto(){
    int id;

    cout<<"ID producto a editar: ";
    cin>>id;

    for(auto &p : productos){

        if(p.id==id){

            cout<<"Nuevo precio venta: ";
            cin>>p.precioVenta;

            cout<<"Nuevo stock: ";
            cin>>p.stock;

            guardarProductos();

            cout<<"Producto actualizado\n";
            return;
        }
    }
}

void eliminarProducto(){
    int id;

    cout<<"ID a eliminar: ";
    cin>>id;

    for(int i=0;i<productos.size();i++){

        if(productos[i].id==id){

            productos.erase(productos.begin()+i);

            guardarProductos();

            cout<<"Producto eliminado\n";
            return;
        }
    }
}

void reponerStock(){
    int id,cantidad;

    cout<<"ID producto: ";
    cin>>id;

    cout<<"Cantidad agregar: ";
    cin>>cantidad;

    for(auto &p : productos){

        if(p.id==id){

            p.stock+=cantidad;

            guardarProductos();

            cout<<"Stock actualizado\n";
        }
    }
}

void stockBajo(){
    cout<<"\nProductos con stock bajo\n";

    for(auto &p : productos){

        if(p.stock<=5){

            cout<<p.nombre<<" "<<p.marca<<" Stock:"<<p.stock<<endl;
        }
    }
}

void agregarCarrito(){

    int id,cantidad;

    cout<<"ID producto: ";
    cin>>id;

    cout<<"Cantidad: ";
    cin>>cantidad;

    for(auto &p : productos){

        if(p.id==id){

            if(cantidad<=p.stock){

                ItemCarrito item;

                item.producto=p;
                item.cantidad=cantidad;

                carrito.push_back(item);

                p.stock-=cantidad;

                guardarProductos();

                cout<<"Producto agregado carrito\n";

            }else{

                cout<<"Stock insuficiente\n";
            }

            return;
        }
    }
}

void quitarCarrito(){

    int id;

    cout<<"ID producto quitar: ";
    cin>>id;

    for(int i=0;i<carrito.size();i++){

        if(carrito[i].producto.id==id){

            carrito.erase(carrito.begin()+i);

            cout<<"Producto eliminado carrito\n";

            return;
        }
    }
}

void verCarrito(){

    float total=0;
    float ganancia=0;

    cout<<"\nCARRITO\n";

    for(auto &c : carrito){

        float subtotal=c.producto.precioVenta*c.cantidad;
        float gan=(c.producto.precioVenta-c.producto.precioCompra)*c.cantidad;

        cout<<c.producto.nombre<<" x"<<c.cantidad<<" = "<<subtotal<<endl;

        total+=subtotal;
        ganancia+=gan;
    }

    cout<<"------------------\n";
    cout<<"TOTAL: "<<total<<endl;
    cout<<"GANANCIA: "<<ganancia<<endl;
}

int main(){

    cargarProductos();

    int op;

    do{

        cout<<"\n==== TIENDA ELECTRONICA ====\n";
        cout<<"1 Agregar producto\n";
        cout<<"2 Listar productos\n";
        cout<<"3 Buscar producto\n";
        cout<<"4 Buscar por codigo\n";
        cout<<"5 Editar producto\n";
        cout<<"6 Eliminar producto\n";
        cout<<"7 Reponer stock\n";
        cout<<"8 Stock bajo\n";
        cout<<"9 Agregar carrito\n";
        cout<<"10 Quitar carrito\n";
        cout<<"11 Ver carrito\n";
        cout<<"0 Salir\n";

        cin>>op;

        switch(op){

            case 1: agregarProducto(); break;
            case 2: listarProductos(); break;
            case 3: buscarProducto(); break;
            case 4: buscarCodigo(); break;
            case 5: editarProducto(); break;
            case 6: eliminarProducto(); break;
            case 7: reponerStock(); break;
            case 8: stockBajo(); break;
            case 9: agregarCarrito(); break;
            case 10: quitarCarrito(); break;
            case 11: verCarrito(); break;

        }

    }while(op!=0);

}