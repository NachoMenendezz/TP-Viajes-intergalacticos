#include <iostream>
#include "clsPasajero.h"
#include "Persona.h"

using namespace std;

Pasajero::Pasajero(int nivel){
    Persona();
    nivelCiudadania = nivel;
}

void Pasajero::setNivelCiudadania(int nivel){
    nivelCiudadania = nivel;
}

int Pasajero::getNivelCiudadania(){
    return nivelCiudadania;
}

void Pasajero::Cargar(int id){
    Persona::Cargar( id);

    cout<<"NIVEL DE CIUDADANIA: ";
    cin>>nivelCiudadania;
}

void Pasajero::Mostrar(){
    Persona::Mostrar();

    cout<<"NIVEL DE CIUDADANIA: "<<nivelCiudadania<<endl;
}

Pasajero::~Pasajero(){
}
