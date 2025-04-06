
#ifndef TIEMPO_HPP
#define TIEMPO_HPP


class Tiempo
{
    private:
        int horas;
        int minutos;
        int segundos;
        bool franja;
    
    public:
        Tiempo(int horas, int minutos, int segundos, bool franja);
        ~Tiempo();

        void setHoras(int horas);
        void setMinutos(int minutos);
        void setSegundos(int segundos);
        void setFranja(bool franja);
        int checktime(int cant, int tipo);
        int getHoras();
        int getMinutos();
        int getSegundos();
        bool getFranja();
        void imprimir();
        void imprimir24hrs();
};


#endif