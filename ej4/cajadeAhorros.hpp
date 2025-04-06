
#ifndef CAJADEAHORROS_HPP
#define CAJADEAHORROS_HPP

#include "cuentaBanco.hpp"

using namespace std;

class CajaDeAhorros : public CuentaBanco 
{
    private:
        // Consultas
        int vecesConsultada = 2;

    public:
        // Constructor y destructor
        CajaDeAhorros(string nombre, double saldo);
        ~CajaDeAhorros() override;
        
        // Métodos
        double retirar(double cantidad) override;
        void mostrarInfo() const override;

    };


#endif