#ifndef CLSPASAJERO_H_INCLUDED
#define CLSPASAJERO_H_INCLUDED

#include "Persona.h"

class Pasajero : public Persona{
    private:
        int nivelCiudadania;

    public:
        Pasajero(int nivel=1);
        void setNivelCiudadania(int);
        int getNivelCiudadania();

        void Cargar(int );
        void Mostrar();

        ~Pasajero();
};

#endif // CLSPASAJERO_H_INCLUDED
