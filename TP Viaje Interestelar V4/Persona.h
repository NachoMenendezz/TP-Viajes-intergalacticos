#ifndef CLSPERSONA_H_INCLUDED
#define CLSPERSONA_H_INCLUDED

#include "clsFecha.h"

class Persona{
    protected:
        int idIntergalactico;
        char nombreApellido[50];
        Fecha fechaNacimiento;
        bool estado;

    public:
        Persona(int id=0, const char *nombre="", Fecha fec=Fecha(), bool est=true);

        void setIdIntergalactico(int);
        void setNombreApellido(const char *);
        void setFechaNacimiento(Fecha);
        void setEstado(bool);

        int getIdIntergalactico();
        const char *getNombreApellido();
        Fecha getFechaNacimiento();
        bool getEstado();

        void Cargar(int);
        void Mostrar();

        ~Persona();
};

#endif // CLSPERSONA_H_INCLUDED
