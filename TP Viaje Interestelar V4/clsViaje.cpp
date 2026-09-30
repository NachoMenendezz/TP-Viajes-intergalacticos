#include <iostream>
#include "clsViaje.h"

using namespace std;

Viaje::Viaje(int id, int cap, int dest, int tiempo, bool est){
    idViaje = id;
    idCapitan = cap;
    idDestino = dest;
    tiempoViaje = tiempo;
    estado = est;
}

void Viaje::setIdViaje(int id){
    idViaje = id;
}

void Viaje::setIdCapitan(int cap){
    idCapitan = cap;
}

void Viaje::setIdDestino(int dest){
    idDestino = dest;
}

void Viaje::setTiempoViaje(int tiempo){
    tiempoViaje = tiempo;
}

void Viaje::setEstado(bool est){
    estado = est;
}

int Viaje::getIdViaje(){
    return idViaje;
}

int Viaje::getIdCapitan(){
    return idCapitan;
}

int Viaje::getIdDestino(){
    return idDestino;
}

int Viaje::getTiempoViaje(){
    return tiempoViaje;
}

bool Viaje::getEstado(){
    return estado;
}

void Viaje::Cargar(int id){
      if(id == -1){
        cout<<"INGRESE EL ID DE VIAJE: ";
        cin>>id;
    }else{
        idViaje = id;
    }

    cout<<"ID CAPITAN: ";
    cin>>idCapitan;

    cout<<"ID DESTINO: ";
    cin>>idDestino;

    cout<<"TIEMPO DE VIAJE: ";
    cin>>tiempoViaje;

}

void Viaje::Mostrar(){
    cout<<"ID VIAJE: "<<idViaje<<endl;
    cout<<"ID CAPITAN: "<<idCapitan<<endl;
    cout<<"ID DESTINO: "<<idDestino<<endl;
    cout<<"TIEMPO DE VIAJE: "<<tiempoViaje<<endl;

}

Viaje::~Viaje(){
}
