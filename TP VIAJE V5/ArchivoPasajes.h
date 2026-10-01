#ifndef ARCHIVOPASAJES_H_INCLUDED
#define ARCHIVOPASAJES_H_INCLUDED
#include "clsPasaje.h"


class ArchivoPasajes
{
private:
    char nombreArchivo[30];

public:
    ArchivoPasajes(const char *n="pasajes.dat");
    Pasaje leerRegistro(int pos);
    int contarRegistros();
    bool grabarRegistro(Pasaje obj);
    bool modificarRegistro (Pasaje obj,int pos);
    int buscarRegistro(int id);
    void listarRegistros();



};


#endif // ARCHIVOPASAJES_H_INCLUDED
