
#include "cuentaCorriente.hpp"
#include <iostream>


// Constructor de Cuenta Corriente
CuentaCorriente::CuentaCorriente(string nombre, double saldo, shared_ptr<CajaDeAhorros> caja) 
{
    this->titular = nombre;
    this->saldo = saldo;
    this->caja = caja;
    cout << "Constructor de Cuenta Corriente" << endl;
}

// Retira una cantidad de dinero de la cuenta corriente y pide a la caja de ahorros
double CuentaCorriente::retirar(double cantidad) 
{
    if (cantidad > saldo)
    {
        double cant = caja->retirar(cantidad - saldo);
        if (cant == 0)
        {
            cout << "Saldo insuficiente en ambas cuentas" << endl;
            return 0;
        }
        else
        {
            saldo = 0;
            cout << "Se retiraron " << cant << " de la caja de ahorros" << endl;
            return cantidad - cant;
        }
    }
    else
    {
        saldo -= cantidad;
        return cantidad;
    }
}
        
// info de la cuenta corriente
void CuentaCorriente::mostrarInfo() const 
{
    cout << "Titular: " << titular + "(Cuenta Corriente)"<< endl;
    cout << "Saldo: " << saldo << endl;
}


// Destructor de Cuenta Corriente
CuentaCorriente::~CuentaCorriente()
{
    cout << "Destructor de Cuenta Corriente" << endl;
}