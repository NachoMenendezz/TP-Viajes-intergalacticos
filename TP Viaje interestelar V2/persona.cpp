#include <iostream>
#include <cstring>
#include "Persona.h"

using namespace std;

Persona::Persona(int id, const char *nombre, Fecha fec, bool est){
    idIntergalactico = id;
    strcpy(nombreApellido, nombre);
    fechaNacimiento = fec;
    estado = est;
}

void Persona::setIdIntergalactico(int id){
    idIntergalactico = id;
}

void Persona::setNombreApellido(const char *nombre){
    strcpy(nombreApellido, nombre);
}

void Persona::setFechaNacimiento(Fecha fec){
    fechaNacimiento = fec;
}

void Persona::setEstado(bool est){
    estado = est;
}

int Persona::getIdIntergalactico(){
    return idIntergalactico;
}

const char *Persona::getNombreApellido(){
    return nombreApellido;
}

Fecha Persona::getFechaNacimiento(){
    return fechaNacimiento;
}

bool Persona::getEstado(){
    return estado;
}

void Persona::Cargar(){
    cout<<"ID INTERGALACTICO: ";
    cin>>idIntergalactico;

    cout<<"NOMBRE Y APELLIDO: ";
    cin.ignore();
    cin.getline(nombreApellido, 50);

    cout<<"FECHA DE NACIMIENTO:"<<endl;
    fechaNacimiento.Cargar();

}

void Persona::Mostrar(){
    cout<<"ID INTERGALACTICO: "<<idIntergalactico<<endl;
    cout<<"NOMBRE Y APELLIDO: "<<nombreApellido<<endl;

    cout<<"FECHA DE NACIMIENTO: ";
    fechaNacimiento.Mostrar();
    cout<<endl;

}

Persona::~Persona(){
}
