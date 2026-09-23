#ifndef CLSCAPITAN_H_INCLUDED
#define CLSCAPITAN_H_INCLUDED

#include "Persona.h"

class Capitan : public Persona{
    private:

        int rango;

    public:
        Capitan(int ran=1);
        void setRango(int);
        int getRango();
        void Cargar();
        void Mostrar();

        ~Capitan();
};

#endif // CLSCAPITAN_H_INCLUDED
