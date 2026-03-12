#include <iostream>
#include "Producto.h"

using namespace std;

Producto::Producto(){
    id=0;
    nombre="";
    marca="";
    modelo="";
    precio=0;
    stock=0;
}

Producto::Producto(int id,string nombre,string marca,string modelo,float precio,int stock){

    this->id=id;
    this->nombre=nombre;
    this->marca=marca;
    this->modelo=modelo;
    this->precio=precio;
    this->stock=stock;

}

void Producto::mostrar(){

    cout<<"\nID: "<<id<<endl;
    cout<<"Producto: "<<nombre<<endl;
    cout<<"Marca: "<<marca<<endl;
    cout<<"Modelo: "<<modelo<<endl;
    cout<<"Precio: "<<precio<<endl;
    cout<<"Stock: "<<stock<<endl;

}

int Producto::getId(){
    return id;
}

string Producto::getNombre(){
    return nombre;
}

float Producto::getPrecio(){
    return precio;
}

int Producto::getStock(){
    return stock;
}

void Producto::reducirStock(int cantidad){
    stock-=cantidad;
}

void Producto::aumentarStock(int cantidad){
    stock+=cantidad;
}