#include <iostream>
#include <cstring>
#include "ArchivoDestinos.h"
using namespace std;

ArchivoDestinos::ArchivoDestinos(const char *n)
{
    strcpy(nombreArchivo,n);
}
Destino ArchivoDestinos::leerRegistro(int pos)
{
    FILE *p=fopen(nombreArchivo,"rb");
    Destino obj;
    if(p == nullptr)
    {
        obj.setIdDestino(-1);
        return obj;
    }
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}
int ArchivoDestinos::contarRegistros()
{
    FILE *p = fopen(nombreArchivo, "rb");
    if(p == nullptr)
    {
        return -1;
    }
    fseek(p, 0, 2);
    int bytes = ftell(p);
    fclose(p);
    return bytes/sizeof(Destino);
}

bool ArchivoDestinos::grabarRegistro(Destino obj)
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
bool ArchivoDestinos::modificarRegistro (Destino obj,int pos)
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
int ArchivoDestinos::buscarRegistro(int id)
{
    int cantReg = contarRegistros();
    for(int i=0; i<cantReg; i++)
    {
        Destino obj = leerRegistro(i);
        if(obj.getIdDestino() == id) return i;
    }
    return -1;

}
void ArchivoDestinos::listarRegistros()
{
    int cantReg = contarRegistros();
    for(int i=0; i<cantReg; i++)
    {
        Destino obj = leerRegistro(i);
        if(obj.getEstado())
        {
            obj.Mostrar();
            cout<<"======================="<<endl;
        }
    }
}
