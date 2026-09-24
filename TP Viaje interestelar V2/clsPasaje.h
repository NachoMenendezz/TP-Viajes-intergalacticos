#ifndef CLSPASAJE_H_INCLUDED
#define CLSPASAJE_H_INCLUDED

#include "clsFecha.h"

class Pasaje{
    private:
        int idPasaje;
        int idViaje;
        int idIntergalactico;
        Fecha fechaCompra;
        bool estado;

    public:
        Pasaje(int id=0, int viaje=0, int pasajero=0, Fecha fecha=Fecha(), bool est=true);

        void setIdPasaje(int);
        void setIdViaje(int);
        void setIdIntergalactico(int);
        void setFechaCompra(Fecha);
        void setEstado(bool);

        int getIdPasaje();
        int getIdViaje();
        int getIdIntergalactico();
        Fecha getFechaCompra();
        bool getEstado();

        void Cargar();
        void Mostrar();

        ~Pasaje();
};

#endif // CLSPASAJE_H_INCLUDED
