
#ifndef CUENTA_CORRIENTE_HPP
#define CUENTA_CORRIENTE_HPP

#include "cuentaBanco.hpp"
#include "cajadeAhorros.hpp"
#include <memory>
#include <string>
using namespace std;

class CajaDeAhorros;

class CuentaCorriente : public CuentaBanco 
{
    private:
        // para acceder mas facil a la caja de ahorros
        shared_ptr<CajaDeAhorros> caja;
        
    public:
        // Constructor y destructor
        CuentaCorriente(string nombre, double saldo, shared_ptr<CajaDeAhorros> caja);
        ~CuentaCorriente() override;
        
        // Metodos
        double retirar(double cantidad);
        void mostrarInfo() const override;
};



#endif