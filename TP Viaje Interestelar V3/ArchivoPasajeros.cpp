#include <iostream>
#include <cstring>
#include "ArchivoPasajeros.h"

using namespace std;

ArchivoPasajeros::ArchivoPasajeros(const char *n)
{
    strcpy(nombreArchivo,n);
}
Pasajero ArchivoPasajeros::leerRegistro(int pos)
{
    FILE *p=fopen(nombreArchivo,"rb");
    Pasajero obj;
    if(p == nullptr)
    {
        obj.setIdIntergalactico(-1);
        return obj;
    }
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}
int ArchivoPasajeros::contarRegistros()
{
    FILE *p = fopen(nombreArchivo, "rb");
    if(p == nullptr)
    {
        return -1;
    }
    fseek(p, 0, 2);
    int bytes = ftell(p);
    fclose(p);
    return bytes/sizeof(Pasajero);
}

bool ArchivoPasajeros::grabarRegistro(Pasajero obj)
{
    FILE *p = fopen(nombreArchivo, "ab");
    if(p == nullptr)
    {
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}
bool ArchivoPasajeros::modificarRegistro (Pasajero obj,int pos)
{
    FILE *p = fopen(nombreArchivo, "rb+");
    ///EL + AGREGA LA FUNCIONALIDAD QUE LE FALTA A MI MODO DE APERTURA.
    if(p == nullptr)
    {
        return false;
    }
    fseek(p, pos * sizeof obj, 0);
    bool modifico = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return modifico;

}
int ArchivoPasajeros::buscarRegistro(int id)
{
    int cantReg = contarRegistros();
    for(int i=0; i<cantReg; i++)
    {
        Pasajero obj = leerRegistro(i);
        if(obj.getIdIntergalactico() == id) return i;
    }
    return -1;

}
void ArchivoPasajeros::listarRegistros()
{
    int cantReg = contarRegistros();
    for(int i=0; i<cantReg; i++)
    {
        Pasajero obj = leerRegistro(i);
        if(obj.getEstado())
        {
            obj.Mostrar();
            cout<<"======================="<<endl;
        }
    }
}
