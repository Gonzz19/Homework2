
#include "cuentaBanco.hpp"
#include "cajadeAhorros.hpp"
#include "cuentaCorriente.hpp"
#include <memory>

using namespace std;


int main() 
{
    // Creo la caja de ahorros
    shared_ptr<CajaDeAhorros> caja = make_shared<CajaDeAhorros>("Juan", 1000.0);
    // Creo la cuenta corriente
    CuentaCorriente cuenta("Juan", 50.0, caja);

    // Pruebo la resta de dinero
    caja->retirar(200.0);
    caja->mostrarInfo();
    caja->mostrarInfo();
    caja->mostrarInfo();

    // Pruebo la cuenta corriente
    cuenta.retirar(20.0);
    cuenta.mostrarInfo();
    cuenta.retirar(100.0);
    cuenta.mostrarInfo();
    cuenta.retirar(1000.0);
    cuenta.mostrarInfo();
    caja->mostrarInfo();

    return 0;
}