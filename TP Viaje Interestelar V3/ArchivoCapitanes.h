#ifndef ARCHIVOCAPITANES_H_INCLUDED
#define ARCHIVOCAPITANES_H_INCLUDED
#include "clsCapitan.h"

class ArchivoCapitanes
{
private:
    char nombreArchivo[30];

public:
    ArchivoCapitanes(const char *n="capitanes.dat");
    Capitan leerRegistro(int pos);
    int contarRegistros();
    bool grabarRegistro(Capitan obj);
    bool modificarRegistro (Capitan obj,int pos);
    int buscarRegistro(int id);
    void listarRegistros();



};

#endif // ARCHIVOCAPITANES_H_INCLUDED
