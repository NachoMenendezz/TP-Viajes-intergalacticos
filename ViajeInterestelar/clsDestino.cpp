#include <iostream>
#include <cstring>
#include "clsDestino.h"

using namespace std;

Destino::Destino(int id, const char *nombre, float dist, bool est){
    idDestino = id;
    strcpy(nombrePlaneta, nombre);
    distancia = dist;
    estado = est;
}

void Destino::setIdDestino(int id){
    idDestino = id;
}

void Destino::setNombrePlaneta(const char *nombre){
    strcpy(nombrePlaneta, nombre);
}

void Destino::setDistancia(float dist){
    distancia = dist;
}

void Destino::setEstado(bool est){
    estado = est;
}

int Destino::getIdDestino(){
    return idDestino;
}

const char *Destino::getNombrePlaneta(){
    return nombrePlaneta;
}

float Destino::getDistancia(){
    return distancia;
}

bool Destino::getEstado(){
    return estado;
}

void Destino::Cargar(){
    cout<<"ID DESTINO: ";
    cin>>idDestino;

    cout<<"NOMBRE DEL PLANETA: ";
    cin.ignore();
    cin.getline(nombrePlaneta, 50);

    cout<<"DISTANCIA DESDE LA TERMINAL: ";
    cin>>distancia;


}

void Destino::Mostrar(){
    cout<<"ID DESTINO: "<<idDestino<<endl;
    cout<<"NOMBRE DEL PLANETA: "<<nombrePlaneta<<endl;
    cout<<"DISTANCIA DESDE LA TERMINAL: "<<distancia<<endl;

}

Destino::~Destino(){
}
