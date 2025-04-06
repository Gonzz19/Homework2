

#include "cuentaBanco.hpp"
#include <iostream>


// Metodo inggresar para todas las clases
void CuentaBanco::ingresar(double cantidad) {
    if (cantidad > 0) {
        saldo += cantidad;
    } else {
        cout << "La cantidad a ingresar debe ser positiva." << endl;
    }
}

