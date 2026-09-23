#ifndef CLSDESTINO_H_INCLUDED
#define CLSDESTINO_H_INCLUDED

class Destino{
    private:
        int idDestino;
        char nombrePlaneta[50];
        float distancia;
        bool estado;

    public:
        Destino(int id=0, const char *nombre="", float dist=0, bool est=true);

        void setIdDestino(int);
        void setNombrePlaneta(const char *);
        void setDistancia(float);
        void setEstado(bool);

        int getIdDestino();
        const char *getNombrePlaneta();
        float getDistancia();
        bool getEstado();

        void Cargar();
        void Mostrar();

        ~Destino();
};

#endif // CLSDESTINO_H_INCLUDED
