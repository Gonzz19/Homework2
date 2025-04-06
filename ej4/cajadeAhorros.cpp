
#include "cajadeAhorros.hpp"
#include <iostream>

// Constructor de la clase CajaDeAhorros
CajaDeAhorros::CajaDeAhorros(string nombre, double saldo)
{
    this->titular = nombre + " (Caja de Ahorros)";
    this->saldo = saldo;
    cout << "Constructor de CajaDeAhorros llamado." << endl;
}

// retirar en caja de ahorros
double CajaDeAhorros::retirar(double cantidad) 
{
    if (cantidad > saldo) 
    {
        cout << "No hay suficiente saldo en la caja" << endl;
        return 0;
    } 

    this->saldo -= cantidad;
    return cantidad;
    
}

// mostrar la info y la bajada de dinero
void CajaDeAhorros::mostrarInfo() const 
{
    if (vecesConsultada == 0)
    {
        const_cast<CajaDeAhorros*>(this)->saldo -=20;
    }
    if (vecesConsultada >0)
    {
        const_cast<CajaDeAhorros*>(this)->vecesConsultada--;
    }
    cout << "Titular: " << titular << endl;
    cout << "Saldo: " << saldo << endl;
}

// Destructor de la clase CajaDeAhorros
CajaDeAhorros::~CajaDeAhorros() 
{
    cout << "Destructor de CajaDeAhorros llamado." << endl;
}