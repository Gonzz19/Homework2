
#ifndef CUENTA_BANCO_HPP
#define CUENTA_BANCO_HPP

#include <string>
using namespace std;


class CuentaBanco 
{
protected:
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