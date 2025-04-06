
#ifndef CUENTA_BANCO_HPP
#define CUENTA_BANCO_HPP

#include <string>
using namespace std;


class CuentaBanco 
{
protected:
    // Uso protected para que las clases derivadas puedan acceder a los atributos
    string titular;
    double saldo;

public:
    // Destructor
    virtual ~CuentaBanco() = default;
    // Metodos
    void ingresar(double cantidad);

    // Metodos virtuales puros
    virtual double retirar(double cantidad) = 0;
    virtual void mostrarInfo() const = 0;
};

#endif