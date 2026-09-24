#ifndef ARCHIVOVIAJE_H_INCLUDED
#define ARCHIVOVIAJE_H_INCLUDED
#include "clsViaje.h"

class ArchivoViajes
{
private:
    char nombreArchivo[30];

public:
    ArchivoViajes(const char *n="viajes.dat");
    Viaje leerRegistro(int pos);
    int contarRegistros();
    bool grabarRegistro(Viaje obj);
    bool modificarRegistro (Viaje obj,int pos);
    int buscarRegistro(int id);
    void listarRegistros();



};




#endif // ARCHIVOVIAJE_H_INCLUDED
