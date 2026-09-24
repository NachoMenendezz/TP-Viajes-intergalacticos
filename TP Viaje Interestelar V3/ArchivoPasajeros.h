#ifndef ARCHIVOPASAJEROS_H_INCLUDED
#define ARCHIVOPASAJEROS_H_INCLUDED
#include "clsPasajero.h"

class ArchivoPasajeros
{
private:
    char nombreArchivo[30];

public:
    ArchivoPasajeros(const char *n="pasajeros.dat");
    Pasajero leerRegistro(int pos);
    int contarRegistros();
    bool grabarRegistro(Pasajero obj);
    bool modificarRegistro (Pasajero obj,int pos);
    int buscarRegistro(int id);
    void listarRegistros();



};


#endif // ARCHIVOPASAJEROS_H_INCLUDED
