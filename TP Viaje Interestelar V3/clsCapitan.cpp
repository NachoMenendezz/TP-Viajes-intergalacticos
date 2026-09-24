#include <iostream>
#include "clsCapitan.h"
#include "Persona.h"
using namespace std;

Capitan::Capitan(int ran){
    Persona();
    rango = ran;
}


void Capitan::setRango(int ran){
    rango = ran;
}


int Capitan::getRango(){
    return rango;
}

void Capitan::Cargar(int id){
    Persona::Cargar(id);

    cout<<"RANGO: ";
    cin>>rango;
}

void Capitan::Mostrar(){
    Persona::Mostrar();

    cout<<"RANGO: "<<rango<<endl;
}

Capitan::~Capitan(){
}
