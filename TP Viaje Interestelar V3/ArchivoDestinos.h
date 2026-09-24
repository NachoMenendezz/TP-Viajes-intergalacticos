#ifndef ARCHIVODESTINOS_H_INCLUDED
#define ARCHIVODESTINOS_H_INCLUDED
#include "clsDestino.h"

class ArchivoDestinos
{
private:
    char nombreArchivo[30];

public:
    ArchivoDestinos(const char *n="destinos.dat");
    Destino leerRegistro(int pos);
    int contarRegistros();
    bool grabarRegistro(Destino obj);
    bool modificarRegistro (Destino obj,int pos);
    int buscarRegistro(int id);
    void listarRegistros();



};


#endif // ARCHIVODESTINOS_H_INCLUDED
