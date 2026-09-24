#ifndef CLSVIAJE_H_INCLUDED
#define CLSVIAJE_H_INCLUDED

class Viaje{
    private:
        int idViaje;
        int idCapitan;
        int idDestino;
        int tiempoViaje;
        bool estado;

    public:
        Viaje(int id=0, int cap=0, int dest=0, int tiempo=0, bool est=true);

        void setIdViaje(int);
        void setIdCapitan(int);
        void setIdDestino(int);
        void setTiempoViaje(int);
        void setEstado(bool);

        int getIdViaje();
        int getIdCapitan();
        int getIdDestino();
        int getTiempoViaje();
        bool getEstado();

        void Cargar(int);
        void Mostrar();

        ~Viaje();
};

#endif // CLSVIAJE_H_INCLUDED
