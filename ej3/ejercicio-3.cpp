
#include "complejos.hpp"
#include "enteros.hpp"
#include "reales.hpp"
#include <iostream>

using namespace std;

int main() 
{
    // Creo los objetos de cada tipo
    shared_ptr<Numero> a = make_shared<Reales>(3.5);
    shared_ptr<Numero> b = make_shared<Reales>(2.0);
    shared_ptr<Numero> c = make_shared<Complejos>(1.0, 2.0);
    shared_ptr<Numero> d = make_shared<Complejos>(3.0, 4.0);
    shared_ptr<Numero> e = make_shared<Enteros>(5);
    shared_ptr<Numero> f = make_shared<Enteros>(10);

    // Esto lo uso para el print
    float h = 3.5, i = 2.0;
    float j = 1.0, k = 2.0;
    float l = 3.0, m = 4.0;
    int n = 5;
    int o = 10;
    
    // Imprimo los resultados de las operaciones, no se puede mezclar clases
    cout << h << " + " << i << " = " << (*a+*b)->toString() << endl;
    cout << h << " - " << i << " = " << (*a-*b)->toString() << endl;
    cout << h << " * " << i << " = " << (*a**b)->toString() << endl;
    cout << j << " + " << k << "i + " << l << " + " << m << "i = " << (*c+*d)->toString() << endl;
    cout << j << " + " << k << "i - " << l << " + " << m << "i = " << (*c-*d)->toString() << endl;
    cout << j << " + " << k << "i * " << l << " + " << m << "i = " << (*c**d)->toString() << endl;
    cout << n << " + " << o << " = " << (*e+*f)->toString() << endl;
    cout << n << " - " << o << " = " << (*e-*f)->toString() << endl;
    cout << n << " * " << o << " = " << (*e**f)->toString() << endl;


    return 0;
}