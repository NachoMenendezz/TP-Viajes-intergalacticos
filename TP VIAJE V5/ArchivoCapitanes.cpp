#include <iostream>
#include <cstring>
#include "ArchivoCapitanes.h"

using namespace std;

ArchivoCapitanes::ArchivoCapitanes(const char *n)
{
    strcpy(nombreArchivo,n);
}
Capitan ArchivoCapitanes::leerRegistro(int pos)
{
    FILE *p=fopen(nombreArchivo,"rb");
    Capitan obj;
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
int ArchivoCapitanes::contarRegistros()
{
    FILE *p = fopen(nombreArchivo, "rb");
    if(p == nullptr)
    {
        return -1;
    }
    fseek(p, 0, 2);
    int bytes = ftell(p);
    fclose(p);
    return bytes/sizeof(Capitan);
}

bool ArchivoCapitanes::grabarRegistro(Capitan obj)
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
bool ArchivoCapitanes::modificarRegistro (Capitan obj,int pos)
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
int ArchivoCapitanes::buscarRegistro(int id)
{
    int cantReg = contarRegistros();
    for(int i=0; i<cantReg; i++)
    {
        Capitan obj = leerRegistro(i);
        if(obj.getIdIntergalactico() == id) return i;
    }
    return -1;

}
void ArchivoCapitanes::listarRegistros()
{
    int cantReg = contarRegistros();
    for(int i=0; i<cantReg; i++)
    {
        Capitan obj = leerRegistro(i);
        if(obj.getEstado())
        {
            obj.Mostrar();
            cout<<"======================="<<endl;
        }
    }
}
