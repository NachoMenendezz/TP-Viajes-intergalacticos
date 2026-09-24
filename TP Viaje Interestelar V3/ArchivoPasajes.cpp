#include <iostream>
#include <cstring>
#include "ArchivoPasajes.h"
using namespace std;

ArchivoPasajes::ArchivoPasajes(const char *n)
{
    strcpy(nombreArchivo,n);
}
Pasaje ArchivoPasajes::leerRegistro(int pos)
{
    FILE *p=fopen(nombreArchivo,"rb");
    Pasaje obj;
    if(p == nullptr)
    {
        obj.setIdPasaje(-1);
        return obj;
    }
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}
int ArchivoPasajes::contarRegistros()
{
    FILE *p = fopen(nombreArchivo, "rb");
    if(p == nullptr)
    {
        return -1;
    }
    fseek(p, 0, 2);
    int bytes = ftell(p);
    fclose(p);
    return bytes/sizeof(Pasaje);
}

bool ArchivoPasajes::grabarRegistro(Pasaje obj)
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
bool ArchivoPasajes::modificarRegistro (Pasaje obj,int pos)
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
int ArchivoPasajes::buscarRegistro(int id)
{
    int cantReg = contarRegistros();
    for(int i=0; i<cantReg; i++)
    {
        Pasaje obj = leerRegistro(i);
        if(obj.getIdPasaje() == id) return i;
    }
    return -1;

}
void ArchivoPasajes::listarRegistros()
{
    int cantReg = contarRegistros();
    for(int i=0; i<cantReg; i++)
    {
        Pasaje obj = leerRegistro(i);
        if(obj.getEstado())
        {
            obj.Mostrar();
            cout<<"======================="<<endl;
        }
    }
}
