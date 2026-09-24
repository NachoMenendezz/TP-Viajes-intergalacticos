#include <iostream>
#include "menus.h"
#include "clsCapitan.h"
#include "clsDestino.h"
#include "clsFecha.h"
#include "clsPasaje.h"
#include "clsPasajero.h"
#include "clsViaje.h"
#include "ArchivoCapitanes.h"
#include "ArchivoDestinos.h"
#include "ArchivoPasajeros.h"
#include "ArchivoPasajes.h"
#include "ArchivoViaje.h"

using namespace std;


void menuPrincipal(){


    while (true)
    {
        int opc;

        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"==================="<<endl;
        cout<<"1.PASAJEROS"<<endl;
        cout<<"2.CAPITANES"<<endl;
        cout<<"3.VIAJES"<<endl;
        cout<<"4.DESTINOS"<<endl;
        cout<<"5.PASAJES"<<endl;
        cout<<"6.REPORTES"<<endl;
        cout<<"0.SALIR"<<endl;
        cout<<"==================="<<endl;
        cout<<"INGRESE UNA OPCION:";
        cin>>opc;
        system("cls");
        switch (opc)
        {
        case 1:
            menuPasajero();
            break;
        case 2:
            menuCapitan();
            break;
        case 3:
            //menuViaje();
            break;
        case 4:
            //menuDestino();
            break;
        case 5:
            //menuPasaje();
            break;
        case 6:
            //menuReportes();
            break;
        case 0:
            return ;
        }
    }

}


void menuPasajero()
{
    int opc;
    while(true){
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"=============="<<endl;
        cout<<"1 - AGREGAR PASAJEROS"<<endl;
        cout<<"2 - BAJA PASAJEROS"<<endl;
        cout<<"3 - MODIFICAR PASAJEROS"<<endl;
        cout<<"4 - LISTAR PASAJEROS"<<endl;
        cout<<"0 - SALIR"<<endl;
        cout<<"=============="<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                agregarPasajero();
                break;
            case 2:
                bajaPasajero();
                break;
            case 3:
                modificarPasajero();
                break;
            case 4:
                listarPasajeros();
                break;
            case 0:
                return;
        }
        system("pause");
    }
}

void listarPasajeros(){
    ArchivoPasajeros arc;
    arc.listarRegistros();
}
void agregarPasajero(){
    Pasajero obj;
    int id;
    cout<<"INGRESE EL ID INTERGALACTICO: ";
    cin>>id;
    if(id <= 0){
        cout<<"EL ID INGRESADO NO ES VALIDO"<<endl;
        return;
    }
    ArchivoPasajeros arc;
    int pos = arc.buscarRegistro(id);
    if(pos >= 0){
        cout<<"EL ID INGRESADO YA EXISTE EN EL ARCHIVO"<<endl;
        return;
    }
    obj.Cargar(id);
    ///VALIDAR LOS DATOS
    ///if(datosValidos){
    arc.grabarRegistro(obj);
    ///}
}

void bajaPasajero(){
    int id;
    cout<<"INGRESE EL ID DEL PASAJERO A DAR DE BAJA: ";
    cin>>id;
    ArchivoPasajeros arc;
    int pos = arc.buscarRegistro(id);
    if(pos < 0){
        cout<<"NO EXISTE EL ID EN EL ARCHIVO"<<endl;
        return;
    }
    Pasajero obj = arc.leerRegistro(pos);
    obj.setEstado(false);
    arc.modificarRegistro(obj, pos);
}

void modificarPasajero(){
    int id;
    cout<<"INGRESE EL ID DEL PASAJERO A MODIFICAR: ";
    cin>>id;
    ArchivoPasajeros arc;
    int pos = arc.buscarRegistro(id);
    if(pos < 0){
        cout<<"NO EXISTE EL ID EN EL ARCHIVO"<<endl;
        return;
    }
    Pasajero obj = arc.leerRegistro(pos);
    char Nombre[50];
    cout<<"INGRESE EL NOMBRE NUEVO: ";
    cin.ignore();
    cin.getline(Nombre, 50);
    obj.setNombreApellido(Nombre);
    arc.modificarRegistro(obj, pos);
}


void menuCapitan()
{
    int opc;
    while(true){
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"=============="<<endl;
        cout<<"1 - AGREGAR CAPITAN"<<endl;
        cout<<"2 - BAJA CAPITAN"<<endl;
        cout<<"3 - MODIFICAR CAPITAN"<<endl;
        cout<<"4 - LISTAR CAPITAN"<<endl;
        cout<<"0 - SALIR"<<endl;
        cout<<"=============="<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                agregarCapitan();
                break;
            case 2:
                bajaCapitan();
                break;
            case 3:
                modificarCapitan();
                break;
            case 4:
                listarCapitanes();
                break;
            case 0:
                return;
        }
        system("pause");
    }
}

void listarCapitanes(){
    ArchivoCapitanes arc;
    arc.listarRegistros();
}
void agregarCapitan(){
    Capitan obj;
    int id;
    cout<<"INGRESE EL ID INTERGALACTICO: ";
    cin>>id;
    if(id <= 0){
        cout<<"EL ID INGRESADO NO ES VALIDO"<<endl;
        return;
    }
    ArchivoCapitanes arc;
    int pos = arc.buscarRegistro(id);
    if(pos >= 0){
        cout<<"EL ID INGRESADO YA EXISTE EN EL ARCHIVO"<<endl;
        return;
    }
    obj.Cargar(id);
    ///VALIDAR LOS DATOS
    ///if(datosValidos){
    arc.grabarRegistro(obj);
    ///}
}

void bajaCapitan(){
    int id;
    cout<<"INGRESE EL ID DEL Capitan A DAR DE BAJA: ";
    cin>>id;
    ArchivoCapitanes arc;
    int pos = arc.buscarRegistro(id);
    if(pos < 0){
        cout<<"NO EXISTE EL ID EN EL ARCHIVO"<<endl;
        return;
    }
    Capitan obj = arc.leerRegistro(pos);
    obj.setEstado(false);
    arc.modificarRegistro(obj, pos);
}

void modificarCapitan(){
    int id;
    cout<<"INGRESE EL ID DEL Capitan A MODIFICAR: ";
    cin>>id;
    ArchivoCapitanes arc;
    int pos = arc.buscarRegistro(id);
    if(pos < 0){
        cout<<"NO EXISTE EL ID EN EL ARCHIVO"<<endl;
        return;
    }
    Capitan obj = arc.leerRegistro(pos);
    int Rango;
    cout<<"INGRESE EL RANGO NUEVO: ";
    cin>>Rango;
    cout<<endl;
    obj.setRango(Rango);
    arc.modificarRegistro(obj, pos);
}

void menuViaje()
{
    int opc;
    while(true){
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"=============="<<endl;
        cout<<"1 - AGREGAR VIAJE"<<endl;
        cout<<"2 - BAJA VIAJE"<<endl;
        cout<<"3 - MODIFICAR VIAJE"<<endl;
        cout<<"4 - LISTAR VIAJES"<<endl;
        cout<<"0 - SALIR"<<endl;
        cout<<"=============="<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                agregarViaje();
                break;
            case 2:
                bajaViaje();
                break;
            case 3:
                modificarViaje();
                break;
            case 4:
                listarViaje();
                break;
            case 0:
                return;
        }
        system("pause");
    }
}

void listarViaje(){
    ArchivoViajes arc;
    arc.listarRegistros();
}
void agregarViaje(){
    Viaje obj;
    int id;
    cout<<"INGRESE EL ID DE VIAJE: ";
    cin>>id;
    if(id <= 0){
        cout<<"EL ID INGRESADO NO ES VALIDO"<<endl;
        return;
    }
    ArchivoViajes arc;
    int pos = arc.buscarRegistro(id);
    if(pos >= 0){
        cout<<"EL ID INGRESADO YA EXISTE EN EL ARCHIVO"<<endl;
        return;
    }
    obj.Cargar(id);
    ///VALIDAR LOS DATOS
    ///if(datosValidos){
    arc.grabarRegistro(obj);
    ///}
}

void bajaViaje(){
    int id;
    cout<<"INGRESE EL ID DEL VIAJE A DAR DE BAJA: ";
    cin>>id;
    ArchivoViajes arc;
    int pos = arc.buscarRegistro(id);
    if(pos < 0){
        cout<<"NO EXISTE EL ID EN EL ARCHIVO"<<endl;
        return;
    }
    Viaje obj = arc.leerRegistro(pos);
    obj.setEstado(false);
    arc.modificarRegistro(obj, pos);
}

void modificarViaje(){
    int id;
    cout<<"INGRESE EL ID DEL VIAJE A MODIFICAR: ";
    cin>>id;
    ArchivoViajes arc;
    int pos = arc.buscarRegistro(id);
    if(pos < 0){
        cout<<"NO EXISTE EL ID EN EL ARCHIVO"<<endl;
        return;
    }
    Viaje obj = arc.leerRegistro(pos);
    int tiempo;
    cout<<"INGRESE EL TIEMPO DE VIAJE NUEVO: ";
    cin>>tiempo;
    obj.setTiempoViaje(tiempo);
    arc.modificarRegistro(obj, pos);
}

void menuDestino()
{
    int opc;
    while(true){
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"=============="<<endl;
        cout<<"1 - AGREGAR Destino"<<endl;
        cout<<"2 - BAJA Destino"<<endl;
        cout<<"3 - MODIFICAR Destino"<<endl;
        cout<<"4 - LISTAR DestinoS"<<endl;
        cout<<"0 - SALIR"<<endl;
        cout<<"=============="<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                agregarDestino();
                break;
            case 2:
                bajaDestino();
                break;
            case 3:
                modificarDestino();
                break;
            case 4:
                listarDestino();
                break;
            case 0:
                return;
        }
        system("pause");
    }
}

void listarDestino(){
    ArchivoDestinos arc;
    arc.listarRegistros();
}
void agregarDestino(){
    Destino obj;
    int id;
    cout<<"INGRESE EL ID DE Destino: ";
    cin>>id;
    if(id <= 0){
        cout<<"EL ID INGRESADO NO ES VALIDO"<<endl;
        return;
    }
    ArchivoDestinos arc;
    int pos = arc.buscarRegistro(id);
    if(pos >= 0){
        cout<<"EL ID INGRESADO YA EXISTE EN EL ARCHIVO"<<endl;
        return;
    }
    obj.Cargar(id);
    ///VALIDAR LOS DATOS
    ///if(datosValidos){
    arc.grabarRegistro(obj);
    ///}
}

void bajaDestino(){
    int id;
    cout<<"INGRESE EL ID DEL Destino A DAR DE BAJA: ";
    cin>>id;
    ArchivoDestinos arc;
    int pos = arc.buscarRegistro(id);
    if(pos < 0){
        cout<<"NO EXISTE EL ID EN EL ARCHIVO"<<endl;
        return;
    }
    Destino obj = arc.leerRegistro(pos);
    obj.setEstado(false);
    arc.modificarRegistro(obj, pos);
}

void modificarDestino(){
    int id;
    cout<<"INGRESE EL ID DEL Destino A MODIFICAR: ";
    cin>>id;
    ArchivoDestinos arc;
    int pos = arc.buscarRegistro(id);
    if(pos < 0){
        cout<<"NO EXISTE EL ID EN EL ARCHIVO"<<endl;
        return;
    }
    Destino obj = arc.leerRegistro(pos);
    float distancia;
    cout<<"INGRESE LA DISTANCIA DEL DESTINO NUEVO: ";
    cin>>distancia;
    obj.setDistancia(distancia);
    arc.modificarRegistro(obj, pos);
}

void menuPasaje()
{
    int opc;
    while(true){
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"=============="<<endl;
        cout<<"1 - AGREGAR Pasaje"<<endl;
        cout<<"2 - BAJA Pasaje"<<endl;
        cout<<"3 - MODIFICAR Pasaje"<<endl;
        cout<<"4 - LISTAR PasajeS"<<endl;
        cout<<"0 - SALIR"<<endl;
        cout<<"=============="<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                agregarPasaje();
                break;
            case 2:
                bajaPasaje();
                break;
            case 3:
                modificarPasaje();
                break;
            case 4:
                listarPasaje();
                break;
            case 0:
                return;
        }
        system("pause");
    }
}

void listarPasaje(){
    ArchivoPasajes arc;
    arc.listarRegistros();
}
void agregarPasaje(){
    Pasaje obj;
    int id, id2;
    cout<<"INGRESE EL ID DE Pasaje: ";
    cin>>id;
    if(id <= 0){
        cout<<"EL ID INGRESADO NO ES VALIDO"<<endl;
        return;
    }
    ArchivoPasajes arc;
    int pos = arc.buscarRegistro(id);
    if(pos >= 0){
        cout<<"EL ID INGRESADO YA EXISTE EN EL ARCHIVO"<<endl;
        return;
    }
     cout<<"INGRESE EL ID DE VIAJE: ";
    cin>>id2;
    if(id2 <= 0){
        cout<<"EL ID INGRESADO NO ES VALIDO"<<endl;
        return;
    }
    pos = arc.buscarRegistro(id2);
    if(pos >= 0){
        cout<<"EL ID INGRESADO YA EXISTE EN EL ARCHIVO"<<endl;
        return;
    }
    obj.Cargar(id, id2);
    ///VALIDAR LOS DATOS
    ///if(datosValidos){
    arc.grabarRegistro(obj);
    ///}
}

void bajaPasaje(){
    int id;
    cout<<"INGRESE EL ID DEL Pasaje A DAR DE BAJA: ";
    cin>>id;
    ArchivoPasajes arc;
    int pos = arc.buscarRegistro(id);
    if(pos < 0){
        cout<<"NO EXISTE EL ID EN EL ARCHIVO"<<endl;
        return;
    }
    Pasaje obj = arc.leerRegistro(pos);
    obj.setEstado(false);
    arc.modificarRegistro(obj, pos);
}

void modificarPasaje(){
    int id;
    cout<<"INGRESE EL ID DEL Pasaje A MODIFICAR: ";
    cin>>id;
    ArchivoPasajes arc;
    int pos = arc.buscarRegistro(id);
    if(pos < 0){
        cout<<"NO EXISTE EL ID EN EL ARCHIVO"<<endl;
        return;
    }
    Pasaje obj = arc.leerRegistro(pos);
    int tiempo;
    cout<<"INGRESE EL TIEMPO DE Pasaje NUEVO: ";
    cin>>tiempo;
    obj.setTiempoPasaje(tiempo);
    arc.modificarRegistro(obj, pos);
}

