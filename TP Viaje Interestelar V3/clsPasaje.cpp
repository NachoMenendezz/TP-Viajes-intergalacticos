#include <iostream>
#include "clsPasaje.h"

using namespace std;

Pasaje::Pasaje(int id, int viaje, int pasajero, Fecha fecha, bool est){
    idPasaje = id;
    idViaje = viaje;
    idIntergalactico = pasajero;
    fechaCompra = fecha;
    estado = est;
}

void Pasaje::setIdPasaje(int id){
    idPasaje = id;
}

void Pasaje::setIdViaje(int viaje){
    idViaje = viaje;
}

void Pasaje::setIdIntergalactico(int pasajero){
    idIntergalactico = pasajero;
}

void Pasaje::setFechaCompra(Fecha fecha){
    fechaCompra = fecha;
}

void Pasaje::setEstado(bool est){
    estado = est;
}

int Pasaje::getIdPasaje(){
    return idPasaje;
}

int Pasaje::getIdViaje(){
    return idViaje;
}

int Pasaje::getIdIntergalactico(){
    return idIntergalactico;
}

Fecha Pasaje::getFechaCompra(){
    return fechaCompra;
}

bool Pasaje::getEstado(){
    return estado;
}

void Pasaje::Cargar(int id, int id2){
          if(id == -1){
        cout<<"INGRESE EL ID DE PASAJE: ";
        cin>>id;
    }else{
        idPasaje = id;
    }
      if(id2 == -1){
        cout<<"INGRESE EL ID DE VIAJE: ";
        cin>>id2;
    }else{
        idViaje = id2;
    }

    cout<<"ID INTERGALACTICO DEL PASAJERO: ";
    cin>>idIntergalactico;

    cout<<"FECHA DE COMPRA:"<<endl;
    fechaCompra.Cargar();

}

void Pasaje::Mostrar(){
    cout<<"ID PASAJE: "<<idPasaje<<endl;
    cout<<"ID VIAJE: "<<idViaje<<endl;
    cout<<"ID INTERGALACTICO DEL PASAJERO: "<<idIntergalactico<<endl;

    cout<<"FECHA DE COMPRA: ";
    fechaCompra.Mostrar();
    cout<<endl;


}

Pasaje::~Pasaje(){
}
