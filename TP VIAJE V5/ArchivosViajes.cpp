#include <iostream>
#include <cstring>
#include "ArchivoViaje.h"
using namespace std;

ArchivoViajes::ArchivoViajes(const char *n)
{
    strcpy(nombreArchivo,n);
}
Viaje ArchivoViajes::leerRegistro(int pos)
{
    FILE *p=fopen(nombreArchivo,"rb");
    Viaje obj;
    if(p == nullptr)
    {
        obj.setIdViaje(-1);
        return obj;
    }
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}
int ArchivoViajes::contarRegistros()
{
    FILE *p = fopen(nombreArchivo, "rb");
    if(p == nullptr)
    {
        return -1;
    }
    fseek(p, 0, 2);
    int bytes = ftell(p);
    fclose(p);
    return bytes/sizeof(Viaje);
}

bool ArchivoViajes::grabarRegistro(Viaje obj)
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
bool ArchivoViajes::modificarRegistro (Viaje obj,int pos)
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
int ArchivoViajes::buscarRegistro(int id)
{
    int cantReg = contarRegistros();
    for(int i=0; i<cantReg; i++)
    {
        Viaje obj = leerRegistro(i);
        if(obj.getIdViaje() == id) return i;
    }
    return -1;

}
void ArchivoViajes::listarRegistros()
{
    int cantReg = contarRegistros();
    for(int i=0; i<cantReg; i++)
    {
        Viaje obj = leerRegistro(i);
        if(obj.getEstado())
        {
            obj.Mostrar();
            cout<<"======================="<<endl;
        }
    }
}

